#include "BaseCombatAIComponent.cpp"
#include "BouncerComponent.cpp"
#include "BuffComponent.cpp"
#include "BuildBorderComponent.cpp"
#include "CharacterComponent.cpp"
#include "Component.cpp"
#include "ControllablePhysicsComponent.cpp"
#include "InventoryComponent.cpp"
#include "LevelProgressionComponent.cpp"
#include "LUPExhibitComponent.cpp"
#include "MissionComponent.cpp"
#include "MissionOfferComponent.cpp"
#include "ModelComponent.cpp"
#include "ModuleAssemblyComponent.cpp"
#include "MovementAIComponent.cpp"
#include "MovingPlatformComponent.cpp"
#include "PetComponent.cpp"
#include "PhantomPhysicsComponent.cpp"
#include "PlayerForcedMovementComponent.cpp"
#include "PossessableComponent.cpp"
#include "PossessorComponent.cpp"
#include "PropertyComponent.cpp"
#include "PropertyEntranceComponent.cpp"
#include "PropertyManagementComponent.cpp"
#include "PropertyVendorComponent.cpp"
#include "ProximityMonitorComponent.cpp"
#include "RacingControlComponent.cpp"
#include "RailActivatorComponent.cpp"
#include "RebuildComponent.cpp"
#include "RenderComponent.cpp"
#include "RigidbodyPhantomPhysicsComponent.cpp"
#include "RocketLaunchLupComponent.cpp"
#include "RocketLaunchpadControlComponent.cpp"
#include "ScriptedActivityComponent.cpp"
#include "ShootingGalleryComponent.cpp"
#include "SimplePhysicsComponent.cpp"
#include "SkillComponent.cpp"
#include "SoundTriggerComponent.cpp"
#include "SwitchComponent.cpp"
#include "VehiclePhysicsComponent.cpp"
#include "VendorComponent.cpp"
#include "GameDependencies.h"
#include <gtest/gtest.h>
#include "BitStream.h"
#include "DestroyableComponent.h"
#include "Entity.h"
class BaseCombatAITest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(BaseCombatAITest, BaseCombatAIComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(uint32_t(m_State)); // NONE uint32_t(m_State)
	outBitStream->Read(m_Target); // NONE m_Target
} 
  
class BouncerTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(BouncerTest, BouncerComponentConstructionTest) {
	outBitStream->Read(m_PetEnabled); // NONE m_PetEnabled
	outBitStream->Read(m_PetBouncerEnabled); // NONE m_PetBouncerEnabled
} 
  
class BuffTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(BuffTest, BuffComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_Buffs.size()); // uint32_t m_Buffs.size()
	outBitStream->Read(buff.first); // uint32_t buff.first
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(0); // uint32_t 0
	outBitStream->ReadBit(); // bool 
} 
  
class CharacterTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(CharacterTest, CharacterComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_Character->GetHairColor()); // NONE m_Character->GetHairColor()
	outBitStream->Read(m_Character->GetHairStyle()); // NONE m_Character->GetHairStyle()
	outBitStream->Read(0); // uint32_t 0
	outBitStream->Read(m_Character->GetShirtColor()); // NONE m_Character->GetShirtColor()
	outBitStream->Read(m_Character->GetPantsColor()); // NONE m_Character->GetPantsColor()
	outBitStream->Read(m_Character->GetShirtStyle()); // NONE m_Character->GetShirtStyle()
	outBitStream->Read(0); // uint32_t 0
	outBitStream->Read(m_Character->GetEyebrows()); // NONE m_Character->GetEyebrows()
	outBitStream->Read(m_Character->GetEyes()); // NONE m_Character->GetEyes()
	outBitStream->Read(m_Character->GetMouth()); // NONE m_Character->GetMouth()
	outBitStream->Read(0); // uint64_t 0
	outBitStream->Read(m_Character->GetLastLogin()); // NONE m_Character->GetLastLogin()
	outBitStream->Read(0); // uint64_t 0
	outBitStream->Read(m_Uscore); // uint64_t m_Uscore
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_CurrencyCollected); // NONE m_CurrencyCollected
	outBitStream->Read(m_BricksCollected); // NONE m_BricksCollected
	outBitStream->Read(m_SmashablesSmashed); // NONE m_SmashablesSmashed
	outBitStream->Read(m_QuickBuildsCompleted); // NONE m_QuickBuildsCompleted
	outBitStream->Read(m_EnemiesSmashed); // NONE m_EnemiesSmashed
	outBitStream->Read(m_RocketsUsed); // NONE m_RocketsUsed
	outBitStream->Read(m_MissionsCompleted); // NONE m_MissionsCompleted
	outBitStream->Read(m_PetsTamed); // NONE m_PetsTamed
	outBitStream->Read(m_ImaginationPowerUpsCollected); // NONE m_ImaginationPowerUpsCollected
	outBitStream->Read(m_LifePowerUpsCollected); // NONE m_LifePowerUpsCollected
	outBitStream->Read(m_ArmorPowerUpsCollected); // NONE m_ArmorPowerUpsCollected
	outBitStream->Read(m_MetersTraveled); // NONE m_MetersTraveled
	outBitStream->Read(m_TimesSmashed); // NONE m_TimesSmashed
	outBitStream->Read(m_TotalDamageTaken); // NONE m_TotalDamageTaken
	outBitStream->Read(m_TotalDamageHealed); // NONE m_TotalDamageHealed
	outBitStream->Read(m_TotalArmorRepaired); // NONE m_TotalArmorRepaired
	outBitStream->Read(m_TotalImaginationRestored); // NONE m_TotalImaginationRestored
	outBitStream->Read(m_TotalImaginationUsed); // NONE m_TotalImaginationUsed
	outBitStream->Read(m_DistanceDriven); // NONE m_DistanceDriven
	outBitStream->Read(m_TimeAirborneInCar); // NONE m_TimeAirborneInCar
	outBitStream->Read(m_RacingImaginationPowerUpsCollected); // NONE m_RacingImaginationPowerUpsCollected
	outBitStream->Read(m_RacingImaginationCratesSmashed); // NONE m_RacingImaginationCratesSmashed
	outBitStream->Read(m_RacingCarBoostsActivated); // NONE m_RacingCarBoostsActivated
	outBitStream->Read(m_RacingTimesWrecked); // NONE m_RacingTimesWrecked
	outBitStream->Read(m_RacingSmashablesSmashed); // NONE m_RacingSmashablesSmashed
	outBitStream->Read(m_RacesFinished); // NONE m_RacesFinished
	outBitStream->Read(m_FirstPlaceRaceFinishes); // NONE m_FirstPlaceRaceFinishes
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_IsLanding); // NONE m_IsLanding
	outBitStream->Read(uint16_t(m_LastRocketConfig.size())); // NONE uint16_t(m_LastRocketConfig.size())
	outBitStream->Read(character); // NONE character
	outBitStream->Read(m_DirtyGMInfo); // NONE m_DirtyGMInfo
	outBitStream->Read(m_PvpEnabled); // NONE m_PvpEnabled
	outBitStream->Read(m_IsGM); // NONE m_IsGM
	outBitStream->Read(m_GMLevel); // NONE m_GMLevel
	outBitStream->Read(m_EditorEnabled); // NONE m_EditorEnabled
	outBitStream->Read(m_EditorLevel); // NONE m_EditorLevel
	outBitStream->Read(m_DirtyCurrentActivity); // NONE m_DirtyCurrentActivity
	if (m_DirtyCurrentActivity) outBitStream->Read(m_CurrentActivity); // NONE m_DirtyCurrentActivity) outBitStream->Read(m_CurrentActivity
	outBitStream->Read(m_DirtySocialInfo); // NONE m_DirtySocialInfo
	outBitStream->Read(m_GuildID); // NONE m_GuildID
	outBitStream->Read(static_cast<unsigned char>(m_GuildName.size())); // unsigned char static_cast<unsigned char>(m_GuildName.size())
	outBitStream->WriteBits(reinterpret_cast<const unsigned char*>(m_GuildName.c_str()), static_cast<unsigned char>(m_GuildName.size()) * sizeof(wchar_t) * 8); // NONE reinterpret_cast<const unsigned char*>(m_GuildName.c_str()), static_cast<unsigned char>(m_GuildName.size()) * sizeof(wchar_t) * 8
	outBitStream->Read(m_IsLEGOClubMember); // NONE m_IsLEGOClubMember
	outBitStream->Read(m_CountryCode); // NONE m_CountryCode
} 
  
class ControllablePhysicsTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(ControllablePhysicsTest, ControllablePhysicsComponentConstructionTest) {
	outBitStream->Read(m_InJetpackMode); // NONE m_InJetpackMode
	outBitStream->Read(m_JetpackEffectID); // NONE m_JetpackEffectID
	outBitStream->Read(m_JetpackFlying); // NONE m_JetpackFlying
	outBitStream->Read(m_JetpackBypassChecks); // NONE m_JetpackBypassChecks
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_DirtyCheats); // NONE m_DirtyCheats
	outBitStream->Read(m_GravityScale); // NONE m_GravityScale
	outBitStream->Read(m_SpeedMultiplier); // NONE m_SpeedMultiplier
	outBitStream->Read(m_DirtyPickupRadiusScale); // NONE m_DirtyPickupRadiusScale
	outBitStream->Read(m_PickupRadius); // NONE m_PickupRadius
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_DirtyPosition || bIsInitialUpdate); // NONE m_DirtyPosition || bIsInitialUpdate
	outBitStream->Read(m_Position.x); // float m_Position.x
	outBitStream->Read(m_Position.y); // float m_Position.y
	outBitStream->Read(m_Position.z); // float m_Position.z
	outBitStream->Read(m_Rotation.x); // float m_Rotation.x
	outBitStream->Read(m_Rotation.y); // float m_Rotation.y
	outBitStream->Read(m_Rotation.z); // float m_Rotation.z
	outBitStream->Read(m_Rotation.w); // float m_Rotation.w
	outBitStream->Read(m_IsOnGround); // NONE m_IsOnGround
	outBitStream->Read(m_IsOnRail); // NONE m_IsOnRail
	outBitStream->Read(m_DirtyVelocity); // NONE m_DirtyVelocity
	outBitStream->Read(m_Velocity.x); // float m_Velocity.x
	outBitStream->Read(m_Velocity.y); // float m_Velocity.y
	outBitStream->Read(m_Velocity.z); // float m_Velocity.z
	outBitStream->Read(m_DirtyAngularVelocity); // NONE m_DirtyAngularVelocity
	outBitStream->Read(m_AngularVelocity.x); // float m_AngularVelocity.x
	outBitStream->Read(m_AngularVelocity.y); // float m_AngularVelocity.y
	outBitStream->Read(m_AngularVelocity.z); // float m_AngularVelocity.z
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_IsTeleporting); // NONE m_IsTeleporting
} 
  
class InventoryTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(InventoryTest, InventoryComponentConstructionTest) {
	outBitStream->Read(true); // NONE true
	outBitStream->Read(m_Equipped.size()); // uint32_t m_Equipped.size()
	outBitStream->Read(item.id); // NONE item.id
	outBitStream->Read(item.lot); // NONE item.lot
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(item.count > 0); // NONE item.count > 0
	if (item.count > 0) outBitStream->Read(item.count); // NONE item.count > 0) outBitStream->Read(item.count
	outBitStream->Read(item.slot != 0); // NONE item.slot != 0
	if (item.slot != 0) outBitStream->Read(item.slot); // uint16_t item.slot != 0) outBitStream->Read(item.slot
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(flag); // NONE flag
	outBitStream->Read(ldfStream.GetNumberOfBytesUsed() + 1); // NONE ldfStream.GetNumberOfBytesUsed() + 1
	outBitStream->Read(0); // uint8_t 0
	outBitStream->Read(ldfStream); // NONE ldfStream
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(false); // NONE false
	outBitStream->Read(false); // NONE false
} 
  
class LevelProgressionTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(LevelProgressionTest, LevelProgressionComponentConstructionTest) {
	outBitStream->Read(bIsInitialUpdate || m_DirtyLevelInfo); // NONE bIsInitialUpdate || m_DirtyLevelInfo
	if (bIsInitialUpdate || m_DirtyLevelInfo) outBitStream->Read(m_Level); // NONE bIsInitialUpdate || m_DirtyLevelInfo) outBitStream->Read(m_Level
} 
  
class LUPExhibitTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(LUPExhibitTest, LUPExhibitComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_Exhibit); // NONE m_Exhibit
} 
  
class ModelTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(ModelTest, ModelComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_userModelID != LWOOBJID_EMPTY ? m_userModelID : m_Parent->GetObjectID()); // LWOOBJID m_userModelID != LWOOBJID_EMPTY ? m_userModelID : m_Parent->GetObjectID()
	outBitStream->Read(0); // int 0
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(2); // uint32_t 2
	outBitStream->Read(m_OriginalPosition); // NONE m_OriginalPosition
	outBitStream->Read(m_OriginalRotation); // NONE m_OriginalRotation
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(0); // uint32_t 0
	outBitStream->ReadBit(); // bool 
	if (bIsInitialUpdate) outBitStream->ReadBit(); // bool bIsInitialUpdate) outBitStream->ReadBit(
} 
  
class ModuleAssemblyTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(ModuleAssemblyTest, ModuleAssemblyComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_SubKey != LWOOBJID_EMPTY); // NONE m_SubKey != LWOOBJID_EMPTY
	outBitStream->Read(m_SubKey); // NONE m_SubKey
	outBitStream->Read(m_UseOptionalParts); // NONE m_UseOptionalParts
	outBitStream->Read(static_cast<uint16_t>(m_AssemblyPartsLOTs.size())); // NONE static_cast<uint16_t>(m_AssemblyPartsLOTs.size())
	outBitStream->Read(character); // NONE character
} 
  
class MoverSubTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(MoverSubTest, MoverSubComponentConstructionTest) {
	outBitStream->Read(true); // bool true
	outBitStream->Read(static_cast<uint32_t>(mState)); // uint32_t static_cast<uint32_t>(mState)
	outBitStream->Read(mDesiredWaypointIndex); // int32_t mDesiredWaypointIndex
	outBitStream->Read(mShouldStopAtDesiredWaypoint); // NONE mShouldStopAtDesiredWaypoint
	outBitStream->Read(mInReverse); // NONE mInReverse
	outBitStream->Read(mPercentBetweenPoints); // float_t mPercentBetweenPoints
	outBitStream->Read(mPosition.x); // float mPosition.x
	outBitStream->Read(mPosition.y); // float mPosition.y
	outBitStream->Read(mPosition.z); // float mPosition.z
	outBitStream->Read(mCurrentWaypointIndex); // uint32_t mCurrentWaypointIndex
	outBitStream->Read(mNextWaypointIndex); // uint32_t mNextWaypointIndex
	outBitStream->Read(mIdleTimeElapsed); // float_t mIdleTimeElapsed
	outBitStream->Read(0.0f); // float_t 0.0f
} 
  
class PetTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(PetTest, PetComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(static_cast<unsigned int>(m_Status)); // uint32_t static_cast<unsigned int>(m_Status)
	outBitStream->Read(static_cast<uint32_t>(tamed ? m_Ability : PetAbilityType::Invalid)); // uint32_t static_cast<uint32_t>(tamed ? m_Ability : PetAbilityType::Invalid)
	outBitStream->Read(interacting); // NONE interacting
	outBitStream->Read(m_Interaction); // NONE m_Interaction
	outBitStream->Read(tamed); // NONE tamed
	outBitStream->Read(m_Owner); // NONE m_Owner
	outBitStream->Read(tamed); // NONE tamed
	outBitStream->Read(m_ModerationStatus); // NONE m_ModerationStatus
	outBitStream->Read(static_cast<uint8_t>(nameData.size())); // NONE static_cast<uint8_t>(nameData.size())
	outBitStream->Read(c); // NONE c
	outBitStream->Read(static_cast<uint8_t>(ownerNameData.size())); // NONE static_cast<uint8_t>(ownerNameData.size())
	outBitStream->Read(c); // NONE c
} 
  
class PhantomPhysicsTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(PhantomPhysicsTest, PhantomPhysicsComponentConstructionTest) {
	outBitStream->Read(m_PositionInfoDirty || bIsInitialUpdate); // NONE m_PositionInfoDirty || bIsInitialUpdate
	outBitStream->Read(m_Position.x); // float m_Position.x
	outBitStream->Read(m_Position.y); // float m_Position.y
	outBitStream->Read(m_Position.z); // float m_Position.z
	outBitStream->Read(m_Rotation.x); // float m_Rotation.x
	outBitStream->Read(m_Rotation.y); // float m_Rotation.y
	outBitStream->Read(m_Rotation.z); // float m_Rotation.z
	outBitStream->Read(m_Rotation.w); // float m_Rotation.w
	outBitStream->Read(m_EffectInfoDirty || bIsInitialUpdate); // NONE m_EffectInfoDirty || bIsInitialUpdate
	outBitStream->Read(m_IsPhysicsEffectActive); // NONE m_IsPhysicsEffectActive
	outBitStream->Read(m_EffectType); // NONE m_EffectType
	outBitStream->Read(m_DirectionalMultiplier); // NONE m_DirectionalMultiplier
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_IsDirectional); // NONE m_IsDirectional
	outBitStream->Read(m_Direction.x); // float m_Direction.x
	outBitStream->Read(m_Direction.y); // float m_Direction.y
	outBitStream->Read(m_Direction.z); // float m_Direction.z
} 
  
class PlayerForcedMovementTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(PlayerForcedMovementTest, PlayerForcedMovementComponentConstructionTest) {
	outBitStream->Read(m_DirtyInfo); // NONE m_DirtyInfo
	outBitStream->Read(m_PlayerOnRail); // NONE m_PlayerOnRail
	outBitStream->Read(m_ShowBillboard); // NONE m_ShowBillboard
} 
  
class PossessableTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(PossessableTest, PossessableComponentConstructionTest) {
	outBitStream->Read(m_DirtyPossessable || bIsInitialUpdate); // NONE m_DirtyPossessable || bIsInitialUpdate
	outBitStream->Read(m_Possessor != LWOOBJID_EMPTY); // NONE m_Possessor != LWOOBJID_EMPTY
	if (m_Possessor != LWOOBJID_EMPTY) outBitStream->Read(m_Possessor); // NONE m_Possessor != LWOOBJID_EMPTY) outBitStream->Read(m_Possessor
	outBitStream->Read(m_AnimationFlag != eAnimationFlags::IDLE_NONE); // NONE m_AnimationFlag != eAnimationFlags::IDLE_NONE
	if (m_AnimationFlag != eAnimationFlags::IDLE_NONE) outBitStream->Read(m_AnimationFlag); // NONE m_AnimationFlag != eAnimationFlags::IDLE_NONE) outBitStream->Read(m_AnimationFlag
	outBitStream->Read(m_ImmediatelyDepossess); // NONE m_ImmediatelyDepossess
} 
  
class PossessorTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(PossessorTest, PossessorComponentConstructionTest) {
	outBitStream->Read(m_DirtyPossesor || bIsInitialUpdate); // NONE m_DirtyPossesor || bIsInitialUpdate
	outBitStream->Read(m_Possessable != LWOOBJID_EMPTY); // NONE m_Possessable != LWOOBJID_EMPTY
	outBitStream->Read(m_Possessable); // NONE m_Possessable
	outBitStream->Read(m_PossessableType); // NONE m_PossessableType
} 
  
class RacingControlTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(RacingControlTest, RacingControlComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(static_cast<uint32_t>(m_RacingPlayers.size())); // NONE static_cast<uint32_t>(m_RacingPlayers.size())
	outBitStream->Read(player.playerID); // NONE player.playerID
	outBitStream->Read(player.data[i]); // NONE player.data[i]
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(static_cast<uint16_t>(m_RacingPlayers.size())); // NONE static_cast<uint16_t>(m_RacingPlayers.size())
	outBitStream->Read(!m_RacingPlayers.empty()); // NONE !m_RacingPlayers.empty()
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(player.playerID); // NONE player.playerID
	outBitStream->Read(player.vehicleID); // NONE player.vehicleID
	outBitStream->Read(player.playerIndex); // NONE player.playerIndex
	outBitStream->Read(player.playerLoaded); // NONE player.playerLoaded
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(!m_RacingPlayers.empty()); // NONE !m_RacingPlayers.empty()
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(player.playerID); // NONE player.playerID
	outBitStream->Read(0); // uint32_t 0
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_RemainingLaps); // NONE m_RemainingLaps
	outBitStream->Read(static_cast<uint16_t>(m_PathName.size())); // NONE static_cast<uint16_t>(m_PathName.size())
	outBitStream->Read(character); // NONE character
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_LeadingPlayer); // NONE m_LeadingPlayer
	outBitStream->Read(m_RaceBestLap); // NONE m_RaceBestLap
	outBitStream->Read(m_RaceBestTime); // NONE m_RaceBestTime
} 
  
class RebuildTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(RebuildTest, RebuildComponentConstructionTest) {
	outBitStream->Read(false); // NONE false
	outBitStream->Read(false); // NONE false
	outBitStream->Read(false); // NONE false
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read((uint32_t)1); // NONE (uint32_t)1
	outBitStream->Read(builder->GetObjectID()); // NONE builder->GetObjectID()
	outBitStream->Read(0.0f); // NONE 0.0f
	outBitStream->Read((uint32_t)0); // NONE (uint32_t)0
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_State); // uint32_t m_State
	outBitStream->Read(m_ShowResetEffect); // NONE m_ShowResetEffect
	outBitStream->Read(m_Activator != nullptr); // NONE m_Activator != nullptr
	outBitStream->Read(m_Timer); // NONE m_Timer
	outBitStream->Read(m_TimerIncomplete); // NONE m_TimerIncomplete
	outBitStream->Read(false); // NONE false
	outBitStream->Read(m_ActivatorPosition); // NONE m_ActivatorPosition
	outBitStream->Read(m_RepositionPlayer); // NONE m_RepositionPlayer
} 
  
class RenderTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(RenderTest, RenderComponentConstructionTest) {
	outBitStream->Read(m_Effects.size()); // uint32_t m_Effects.size()
	outBitStream->Read(eff->name.size()); // uint8_t eff->name.size()
	outBitStream->Read(value); // uint8_t value
	outBitStream->Read(eff->effectID); // NONE eff->effectID
	outBitStream->Read(eff->type.size()); // uint8_t eff->type.size()
	outBitStream->Read(value); // uint16_t value
	outBitStream->Read(eff->scale); // float_t eff->scale
	outBitStream->Read(eff->secondary); // int64_t eff->secondary
} 
  
class RigidbodyPhantomPhysicsTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(RigidbodyPhantomPhysicsTest, RigidbodyPhantomPhysicsComponentConstructionTest) {
	outBitStream->Read(m_IsDirty || bIsInitialUpdate); // NONE m_IsDirty || bIsInitialUpdate
	outBitStream->Read(m_Position.x); // float m_Position.x
	outBitStream->Read(m_Position.y); // float m_Position.y
	outBitStream->Read(m_Position.z); // float m_Position.z
	outBitStream->Read(m_Rotation.x); // float m_Rotation.x
	outBitStream->Read(m_Rotation.y); // float m_Rotation.y
	outBitStream->Read(m_Rotation.z); // float m_Rotation.z
	outBitStream->Read(m_Rotation.w); // float m_Rotation.w
} 
  
class ScriptedActivityTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(ScriptedActivityTest, ScriptedActivityComponentConstructionTest) {
	outBitStream->Read(true); // NONE true
	outBitStream->Read(m_ActivityPlayers.size()); // uint32_t m_ActivityPlayers.size()
	outBitStream->Read(activityPlayer->playerID); // LWOOBJID activityPlayer->playerID
	outBitStream->Read(activityValue); // float_t activityValue
} 
  
class ShootingGalleryTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(ShootingGalleryTest, ShootingGalleryComponentConstructionTest) {
	outBitStream->Read(true); // bool true
	outBitStream->Read(0); // uint32_t 0
	outBitStream->Read(1); // uint32_t 1
	outBitStream->Read(0.0f); // float_t 0.0f
	outBitStream->Read(m_StaticParams.cameraPosition.GetX()); // float_t m_StaticParams.cameraPosition.GetX()
	outBitStream->Read(m_StaticParams.cameraPosition.GetY()); // float_t m_StaticParams.cameraPosition.GetY()
	outBitStream->Read(m_StaticParams.cameraPosition.GetZ()); // float_t m_StaticParams.cameraPosition.GetZ()
	outBitStream->Read(m_StaticParams.cameraLookatPosition.GetX()); // float_t m_StaticParams.cameraLookatPosition.GetX()
	outBitStream->Read(m_StaticParams.cameraLookatPosition.GetY()); // float_t m_StaticParams.cameraLookatPosition.GetY()
	outBitStream->Read(m_StaticParams.cameraLookatPosition.GetZ()); // float_t m_StaticParams.cameraLookatPosition.GetZ()
	outBitStream->Read(m_Dirty || isInitialUpdate); // bool m_Dirty || isInitialUpdate
	outBitStream->Read(m_DynamicParams.cannonVelocity); // double_t m_DynamicParams.cannonVelocity
	outBitStream->Read(m_DynamicParams.cannonRefireRate); // double_t m_DynamicParams.cannonRefireRate
	outBitStream->Read(m_DynamicParams.cannonMinDistance); // double_t m_DynamicParams.cannonMinDistance
	outBitStream->Read(m_DynamicParams.cameraBarrelOffset.GetX()); // float_t m_DynamicParams.cameraBarrelOffset.GetX()
	outBitStream->Read(m_DynamicParams.cameraBarrelOffset.GetY()); // float_t m_DynamicParams.cameraBarrelOffset.GetY()
	outBitStream->Read(m_DynamicParams.cameraBarrelOffset.GetZ()); // float_t m_DynamicParams.cameraBarrelOffset.GetZ()
	outBitStream->Read(m_DynamicParams.cannonAngle); // float_t m_DynamicParams.cannonAngle
	outBitStream->Read(m_DynamicParams.facing.GetX()); // float_t m_DynamicParams.facing.GetX()
	outBitStream->Read(m_DynamicParams.facing.GetY()); // float_t m_DynamicParams.facing.GetY()
	outBitStream->Read(m_DynamicParams.facing.GetZ()); // float_t m_DynamicParams.facing.GetZ()
	outBitStream->Read(m_CurrentPlayerID); // LWOOBJID m_CurrentPlayerID
	outBitStream->Read(m_DynamicParams.cannonTimeout); // float_t m_DynamicParams.cannonTimeout
	outBitStream->Read(m_DynamicParams.cannonFOV); // float_t m_DynamicParams.cannonFOV
} 
  
class SimplePhysicsTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(SimplePhysicsTest, SimplePhysicsComponentConstructionTest) {
	outBitStream->Read(m_ClimbableType != eClimbableType::CLIMBABLE_TYPE_NOT); // NONE m_ClimbableType != eClimbableType::CLIMBABLE_TYPE_NOT
	outBitStream->Read(m_ClimbableType); // NONE m_ClimbableType
	outBitStream->Read(m_DirtyVelocity || bIsInitialUpdate); // NONE m_DirtyVelocity || bIsInitialUpdate
	outBitStream->Read(m_Velocity); // NONE m_Velocity
	outBitStream->Read(m_AngularVelocity); // NONE m_AngularVelocity
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_PhysicsMotionState); // uint32_t m_PhysicsMotionState
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(m_IsDirty || bIsInitialUpdate); // NONE m_IsDirty || bIsInitialUpdate
	outBitStream->Read(m_Position.x); // float m_Position.x
	outBitStream->Read(m_Position.y); // float m_Position.y
	outBitStream->Read(m_Position.z); // float m_Position.z
	outBitStream->Read(m_Rotation.x); // float m_Rotation.x
	outBitStream->Read(m_Rotation.y); // float m_Rotation.y
	outBitStream->Read(m_Rotation.z); // float m_Rotation.z
	outBitStream->Read(m_Rotation.w); // float m_Rotation.w
} 
  
class SkillTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(SkillTest, SkillComponentConstructionTest) {
	if (bIsInitialUpdate) outBitStream->ReadBit(); // bool bIsInitialUpdate) outBitStream->ReadBit(
} 
  
class SoundTriggerTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(SoundTriggerTest, SoundTriggerComponentConstructionTest) {
	outBitStream->Read(dirty); // NONE dirty
	outBitStream->Read(this->musicCues.size()); // uint8_t this->musicCues.size()
	outBitStream->Read(musicCue.name.size()); // uint8_t musicCue.name.size()
	outBitStream->Read(musicCue.name.c_str(), musicCue.name.size()); // NONE musicCue.name.c_str(), musicCue.name.size()
	outBitStream->Read(musicCue.result); // uint32_t musicCue.result
	outBitStream->Read(musicCue.boredomTime); // float_t musicCue.boredomTime
	outBitStream->Read(0); // uint16_t 0
	outBitStream->Read(this->guids.size()); // uint8_t this->guids.size()
	outBitStream->Read(guid.GetData1()); // uint32_t guid.GetData1()
	outBitStream->Read(guid.GetData2()); // uint16_t guid.GetData2()
	outBitStream->Read(guid.GetData3()); // uint16_t guid.GetData3()
	outBitStream->Read(guidSubPart); // uint8_t guidSubPart
	outBitStream->Read(1); // uint32_t 1
	outBitStream->Read(this->mixerPrograms.size()); // uint8_t this->mixerPrograms.size()
	outBitStream->Read(mixerProgram.size()); // uint8_t mixerProgram.size()
	outBitStream->Read(mixerProgram.c_str(), mixerProgram.size()); // NONE mixerProgram.c_str(), mixerProgram.size()
	outBitStream->Read(1); // uint32_t 1
} 
  
class SwitchTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(SwitchTest, SwitchComponentConstructionTest) {
	outBitStream->Read(m_Active); // NONE m_Active
} 
  
class VehiclePhysicsTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(VehiclePhysicsTest, VehiclePhysicsComponentConstructionTest) {
	outBitStream->Read(bIsInitialUpdate || m_DirtyPosition); // NONE bIsInitialUpdate || m_DirtyPosition
	outBitStream->Read(m_Position); // NONE m_Position
	outBitStream->Read(m_Rotation); // NONE m_Rotation
	outBitStream->Read(m_IsOnGround); // NONE m_IsOnGround
	outBitStream->Read(m_IsOnRail); // NONE m_IsOnRail
	outBitStream->Read(bIsInitialUpdate || m_DirtyVelocity); // NONE bIsInitialUpdate || m_DirtyVelocity
	outBitStream->Read(m_Velocity); // NONE m_Velocity
	outBitStream->Read(bIsInitialUpdate || m_DirtyAngularVelocity); // NONE bIsInitialUpdate || m_DirtyAngularVelocity
	outBitStream->Read(m_AngularVelocity); // NONE m_AngularVelocity
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(0.0f); // NONE 0.0f
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(5); // uint8_t 5
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
} 
  
class VendorTest : public GameDependenciesTest {
void SetUp() override {
    SetUpDependencies();
}
void TearDown() override {
    TearDownDependencies();
}
};
TEST_F(VendorTest, VendorComponentConstructionTest) {
	outBitStream->ReadBit(); // bool 
	outBitStream->ReadBit(); // bool 
	outBitStream->Read(HasCraftingStation()); // NONE HasCraftingStation()
} 
  
