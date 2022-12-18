import os

files = os.listdir(".")

outFile = open("out2.txt", "w")
outFile.write("""#include "GameDependencies.h"
#include <gtest/gtest.h>

#include "BitStream.h"
#include "DestroyableComponent.h"
#include "Entity.h"


""")
i = 0
for file in files:
    if file.endswith(".h") or file.endswith(".py") or file.endswith(".txt") or file.find("DestroyableComponent") != -1:
        continue
    readFile = open(file, "r")
    contents = readFile.read().split("\n")
    braceIndent = -1
    for line in contents:
        if line.isspace() or line.lstrip().startswith("//"):
            continue
        if line.find("::Serialize(") != -1:
            braceIndent = 1
            componentName = line.split(" ")[1].split("::")[0].replace("Component", "")
            outFile.write(
"""
class componentName : public GameDependenciesTest {
protected:
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
""".replace("componentName", componentName + "Test"))
            line = "TEST_F(" + componentName + "Test, " + line.split(" ")[1].split("::")[0] + "ConstructionTest" + ") {"
            outFile.write(line + "\n")
            continue
        if braceIndent == -1:
            continue
        parsedLine = line
        typeOfVar = "NONE"
        if line.find("Write1") != -1:
            parsedLine = line.replace("Write1", "ReadBit")
            typeOfVar = "bool"
        if line.find("Write0") != -1:
            parsedLine = line.replace("Write0", "ReadBit")
            typeOfVar = "bool"
        if line.find("Write(") != -1:
            parsedLine = line.replace("Write", "Read")
        if line.find("Write<") != -1:
            position = line.find("<")
            endPosition = line.find(">(")
            typeOfVar = line[position + 1: endPosition]
            parsedLine = line[0:position] + line[endPosition + 1:]
            parsedLine = parsedLine.replace("Write", "Read")
        if line.find(".x") != -1 or line.find(".y") != -1 or line.find(".z") != -1 or line.find(".w") != -1:
            typeOfVar = "float"
        leftPos = parsedLine.find("(")
        rightPos = parsedLine.rfind(");")
        parsedLine = parsedLine[0:rightPos + 2]
        
        variable = " // " + typeOfVar + " " + parsedLine[leftPos + 1:rightPos]
        parsedLine = parsedLine.lstrip()
        outFile.write("\t" + parsedLine + variable + "\n")
        if line.find("{") != -1:
            braceIndent += 1
        if line.find("}") != -1:
            braceIndent -= 1
        if braceIndent == 0:
            braceIndent = -1
            # outFile.write("}")
            break
outFile.close()
outFile = open("out2.txt", "r")
otherOutFile = open("out.cpp", "w")

for file in files:
    if file.endswith(".h") or file.endswith(".py") or file.endswith(".txt") or file.find("DestroyableComponent") != -1 or file.find("out.cpp") != -1:
        continue
    otherOutFile.write("#include \"" + file + "\"\n")

lines = outFile.read().split("\n")
for line in lines:
    if line.find("SetUpDepen") != -1 or line.find("TearDownDepen") != -1:
        otherOutFile.write(line + "\n")
        continue
    if line.replace("//", "").isspace():
        continue
    if line.find("outBitStream") == -1 and (line.find("{") == -1 and line.find("}") == -1) and line.find("#include") == -1:
        continue
    if line.find("}") != -1:
        line = line.replace("//", "\n").replace("\t", "").replace("NONE", "")
    otherOutFile.write(line + "\n")

outFile.close()
otherOutFile.close()
