#include "Logger.h"

std::vector<std::string> Logger::fileLogLevel = {
		"", // INFO
		"WARNING: ", // WARNING
		"ERROR: "  // ERROR
	};

std::vector<std::string> Logger::consoleLogLevel{
		"", // INFO
		"\033[1;33mWARNING: \033[0m", // WARNING
		"\033[1;31mERROR: \033[0m"  // ERROR
	};

Logger::~Logger() {
	if (m_File.good()) m_File.flush();
}

void Logger::Initialize(const std::string& outpath, bool logToConsole, bool logDebugStatements) {
	m_logToConsole = logToConsole;
	m_logDebugStatements = logDebugStatements;
	m_File = std::ofstream(outpath);
}

void Logger::_Log(const char* filename, const char* format, LogLevel logLevel, va_list args) {
	time_t t = time(NULL);
	struct tm* time = localtime(&t);
	char timeStr[70];
	strftime(timeStr, sizeof(timeStr), "%d-%m-%y %H:%M:%S", time);
	char message[2048];
	std::cout << filename << std::endl;
	vsnprintf(message, 2048, format, args);
	std::cout << '(' << logLevel << ')' << this->fileLogLevel.size() << " " << this->consoleLogLevel.size() << std::endl;
	if (m_logToConsole) {
		fputc('[', stdout);
		fputs(timeStr, stdout);
		fputc(' ', stdout);
		fputs(filename, stdout);
		fputs("] ", stdout);
		fputs(consoleLogLevel.at(logLevel).c_str(), stdout);
		fputs(message, stdout);
		fputc('\n', stdout);
	}
	if (m_File.good()) m_File << '[' << timeStr << ' ' << filename << ']' << fileLogLevel.at(logLevel) << message << '\n';
	else std::cout << "Log file is not in a good state and cannot be written to.\n";
}

void Logger::_Log(const char* filename, const char* format, ...) {
	va_list args;
	va_start(args, format);
	_Log(filename, format, LogLevel::INFO, args);
	va_end(args);
}

void Logger::_LogWarning(const char* filename, const char* format, ...) {
	va_list args;
	va_start(args, format);
	_Log(filename, format, LogLevel::WARNING, args);
	va_end(args);
}

void Logger::_LogError(const char* filename, const char* format, ...) {
	va_list args;
	va_start(args, format);
	_Log(filename, format, LogLevel::ERROR, args);
	va_end(args);
}
