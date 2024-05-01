#include <Windows.h>

#include "include/gomp.h"

std::unordered_map<std::string, void*> funcs;

#ifdef __cplusplus
extern "C"
{
#endif

    void* openLib(const char* path)
    {
        return LoadLibrary((LPCTSTR)path);
    }

    void* findFunc(void* handle, const char* name)
    {
        FARPROC func = GetProcAddress((HMODULE)handle, name);

        return (void*)func;
    }

    void initFuncs(void* handle)
    {
        funcs.emplace("freeArray", findFunc(handle, "freeArray"));

        // Actor
        funcs.emplace("actor_create", findFunc(handle, "actor_create"));
        funcs.emplace("actor_release", findFunc(handle, "actor_release"));
        funcs.emplace("actor_setSkin", findFunc(handle, "actor_setSkin"));
        funcs.emplace("actor_getSkin", findFunc(handle, "actor_getSkin"));
        funcs.emplace("actor_applyAnimation", findFunc(handle, "actor_applyAnimation"));
        funcs.emplace("actor_getAnimation", findFunc(handle, "actor_getAnimation"));
        funcs.emplace("actor_clearAnimations", findFunc(handle, "actor_clearAnimations"));
        funcs.emplace("actor_setHealth", findFunc(handle, "actor_setHealth"));
        funcs.emplace("actor_getHealth", findFunc(handle, "actor_getHealth"));
        funcs.emplace("actor_setInvulnerable", findFunc(handle, "actor_setInvulnerable"));
        funcs.emplace("actor_isInvulnerable", findFunc(handle, "actor_isInvulnerable"));
        funcs.emplace("actor_isStreamedInForPlayer", findFunc(handle, "actor_isStreamedInForPlayer"));
        funcs.emplace("actor_getSpawnData", findFunc(handle, "actor_getSpawnData"));
        funcs.emplace("actor_setPosition", findFunc(handle, "actor_setPosition"));
        funcs.emplace("actor_getPosition", findFunc(handle, "actor_getPosition"));
        funcs.emplace("actor_setVirtualWorld", findFunc(handle, "actor_setVirtualWorld"));
        funcs.emplace("actor_getVirtualWorld", findFunc(handle, "actor_getVirtualWorld"));
        funcs.emplace("actor_setFacingAngle", findFunc(handle, "actor_setFacingAngle"));
        funcs.emplace("actor_getFacingAngle", findFunc(handle, "actor_getFacingAngle"));

        funcs.emplace("server_setModeText", findFunc(handle, "server_setModeText"));
        funcs.emplace("server_enableStuntBonuses", findFunc(handle, "server_enableStuntBonuses"));
        funcs.emplace("server_setWeather", findFunc(handle, "server_setWeather"));
        funcs.emplace("server_setWorldTime", findFunc(handle, "server_setWorldTime"));

        funcs.emplace("config_setFloat", findFunc(handle, "config_setFloat"));
        funcs.emplace("config_setInt", findFunc(handle, "config_setInt"));
        funcs.emplace("config_setBool", findFunc(handle, "config_setBool"));
        funcs.emplace("config_getType", findFunc(handle, "config_getType"));
        funcs.emplace("config_getFloat", findFunc(handle, "config_getFloat"));
        funcs.emplace("config_getInt", findFunc(handle, "config_getInt"));
        funcs.emplace("config_getBool", findFunc(handle, "config_getBool"));

        funcs.emplace("checkpoint_setPosition", findFunc(handle, "checkpoint_setPosition"));
        funcs.emplace("checkpoint_getPosition", findFunc(handle, "checkpoint_getPosition"));
        funcs.emplace("checkpoint_setRadius", findFunc(handle, "checkpoint_setRadius"));
        funcs.emplace("checkpoint_getRadius", findFunc(handle, "checkpoint_getRadius"));
        funcs.emplace("checkpoint_isPlayerInside", findFunc(handle, "checkpoint_isPlayerInside"));
        funcs.emplace("checkpoint_enable", findFunc(handle, "checkpoint_enable"));
        funcs.emplace("checkpoint_disable", findFunc(handle, "checkpoint_disable"));
        funcs.emplace("checkpoint_isEnabled", findFunc(handle, "checkpoint_isEnabled"));
        funcs.emplace("raceCheckpoint_setPosition", findFunc(handle, "raceCheckpoint_setPosition"));
        funcs.emplace("raceCheckpoint_getPosition", findFunc(handle, "raceCheckpoint_getPosition"));
        funcs.emplace("raceCheckpoint_setRadius", findFunc(handle, "raceCheckpoint_setRadius"));
        funcs.emplace("raceCheckpoint_getRadius", findFunc(handle, "raceCheckpoint_getRadius"));
        funcs.emplace("raceCheckpoint_isPlayerInside", findFunc(handle, "raceCheckpoint_isPlayerInside"));
        funcs.emplace("raceCheckpoint_enable", findFunc(handle, "raceCheckpoint_enable"));
        funcs.emplace("raceCheckpoint_disable", findFunc(handle, "raceCheckpoint_disable"));
        funcs.emplace("raceCheckpoint_isEnabled", findFunc(handle, "raceCheckpoint_isEnabled"));
        funcs.emplace("raceCheckpoint_setType", findFunc(handle, "raceCheckpoint_setType"));
        funcs.emplace("raceCheckpoint_getType", findFunc(handle, "raceCheckpoint_getType"));
        funcs.emplace("raceCheckpoint_setNextPosition", findFunc(handle, "raceCheckpoint_setNextPosition"));
        funcs.emplace("raceCheckpoint_getNextPosition", findFunc(handle, "raceCheckpoint_getNextPosition"));

        funcs.emplace("class_create", findFunc(handle, "class_create"));
        funcs.emplace("class_release", findFunc(handle, "class_release"));
        funcs.emplace("class_getID", findFunc(handle, "class_getID"));
        funcs.emplace("class_setClass", findFunc(handle, "class_setClass"));
        funcs.emplace("class_getClass", findFunc(handle, "class_getClass"));

        // GangZone
        funcs.emplace("gangZone_create", findFunc(handle, "gangZone_create"));
        funcs.emplace("gangZone_release", findFunc(handle, "gangZone_release"));
        funcs.emplace("gangZone_useCheck", findFunc(handle, "gangZone_useCheck"));
        funcs.emplace("gangZone_isShownForPlayer", findFunc(handle, "gangZone_isShownForPlayer"));
        funcs.emplace("gangZone_isFlashingForPlayer", findFunc(handle, "gangZone_isFlashingForPlayer"));
        funcs.emplace("gangZone_showForPlayer", findFunc(handle, "gangZone_showForPlayer"));
        funcs.emplace("gangZone_showForAll", findFunc(handle, "gangZone_showForAll"));
        funcs.emplace("gangZone_hideForPlayer", findFunc(handle, "gangZone_hideForPlayer"));
        funcs.emplace("gangZone_hideForAll", findFunc(handle, "gangZone_hideForAll"));
        funcs.emplace("gangZone_flashForPlayer", findFunc(handle, "gangZone_flashForPlayer"));
        funcs.emplace("gangZone_flashForAll", findFunc(handle, "gangZone_flashForAll"));
        funcs.emplace("gangZone_stopFlashForPlayer", findFunc(handle, "gangZone_stopFlashForPlayer"));
        funcs.emplace("gangZone_stopFlashForAll", findFunc(handle, "gangZone_stopFlashForAll"));
        funcs.emplace("gangZone_getPosition", findFunc(handle, "gangZone_getPosition"));
        funcs.emplace("gangZone_setPosition", findFunc(handle, "gangZone_setPosition"));
        funcs.emplace("gangZone_isPlayerInside", findFunc(handle, "gangZone_isPlayerInside"));
        funcs.emplace("gangZone_getFlashingColourForPlayer", findFunc(handle, "gangZone_getFlashingColourForPlayer"));
        funcs.emplace("gangZone_getColourForPlayer", findFunc(handle, "gangZone_getColourForPlayer"));

        funcs.emplace("playerGangZone_create", findFunc(handle, "playerGangZone_create"));
        funcs.emplace("playerGangZone_release", findFunc(handle, "playerGangZone_release"));

        // Menu
        funcs.emplace("menu_create", findFunc(handle, "menu_create"));
        funcs.emplace("menu_release", findFunc(handle, "menu_release"));
        funcs.emplace("menu_setColumnHeader", findFunc(handle, "menu_setColumnHeader"));
        funcs.emplace("menu_addCell", findFunc(handle, "menu_addCell"));
        funcs.emplace("menu_disableRow", findFunc(handle, "menu_disableRow"));
        funcs.emplace("menu_isRowEnabled", findFunc(handle, "menu_isRowEnabled"));
        funcs.emplace("menu_disable", findFunc(handle, "menu_disable"));
        funcs.emplace("menu_isEnabled", findFunc(handle, "menu_isEnabled"));
        funcs.emplace("menu_getPosition", findFunc(handle, "menu_getPosition"));
        funcs.emplace("menu_getRowCount", findFunc(handle, "menu_getRowCount"));
        funcs.emplace("menu_getColumnCount", findFunc(handle, "menu_getColumnCount"));
        funcs.emplace("menu_getColumnWidths", findFunc(handle, "menu_getColumnWidths"));
        funcs.emplace("menu_getColumnHeader", findFunc(handle, "menu_getColumnHeader"));
        funcs.emplace("menu_getCell", findFunc(handle, "menu_getCell"));
        funcs.emplace("menu_showForPlayer", findFunc(handle, "menu_showForPlayer"));
        funcs.emplace("menu_hideForPlayer", findFunc(handle, "menu_hideForPlayer"));

        // CustomModel
        funcs.emplace("customModel_add", findFunc(handle, "customModel_add"));
        funcs.emplace("customModel_getNameFromCheckSum", findFunc(handle, "customModel_getNameFromCheckSum"));
        funcs.emplace("customModel_getPath", findFunc(handle, "customModel_getPath"));

        // Object
        funcs.emplace("object_create", findFunc(handle, "object_create"));
        funcs.emplace("object_release", findFunc(handle, "object_release"));
        funcs.emplace("object_getByID", findFunc(handle, "object_getByID"));
        funcs.emplace("object_setDefaultCameraCollision", findFunc(handle, "object_setDefaultCameraCollision"));
        funcs.emplace("object_setDrawDistance", findFunc(handle, "object_setDrawDistance"));
        funcs.emplace("object_getDrawDistance", findFunc(handle, "object_getDrawDistance"));
        funcs.emplace("object_setModel", findFunc(handle, "object_setModel"));
        funcs.emplace("object_getModel", findFunc(handle, "object_getModel"));
        funcs.emplace("object_setCameraCollision", findFunc(handle, "object_setCameraCollision"));
        funcs.emplace("object_getCameraCollision", findFunc(handle, "object_getCameraCollision"));
        funcs.emplace("object_move", findFunc(handle, "object_move"));
        funcs.emplace("object_isMoving", findFunc(handle, "object_isMoving"));
        funcs.emplace("object_stop", findFunc(handle, "object_stop"));
        funcs.emplace("object_getMovingData", findFunc(handle, "object_getMovingData"));
        funcs.emplace("object_attachToVehicle", findFunc(handle, "object_attachToVehicle"));
        funcs.emplace("object_resetAttachment", findFunc(handle, "object_resetAttachment"));
        funcs.emplace("object_getAttachmentData", findFunc(handle, "object_getAttachmentData"));
        funcs.emplace("object_isMaterialSlotUsed", findFunc(handle, "object_isMaterialSlotUsed"));
        funcs.emplace("object_getMaterial", findFunc(handle, "object_getMaterial"));
        funcs.emplace("object_getMaterialText", findFunc(handle, "object_getMaterialText"));
        funcs.emplace("object_setMaterial", findFunc(handle, "object_setMaterial"));
        funcs.emplace("object_setMaterialText", findFunc(handle, "object_setMaterialText"));
        funcs.emplace("object_attachToPlayer", findFunc(handle, "object_attachToPlayer"));
        funcs.emplace("object_attachToObject", findFunc(handle, "object_attachToObject"));

        funcs.emplace("object_setPosition", findFunc(handle, "object_setPosition"));
        funcs.emplace("object_getPosition", findFunc(handle, "object_getPosition"));
        funcs.emplace("object_setRotation", findFunc(handle, "object_setRotation"));
        funcs.emplace("object_getRotation", findFunc(handle, "object_getRotation"));

        funcs.emplace("playerObject_create", findFunc(handle, "playerObject_create"));
        funcs.emplace("playerObject_release", findFunc(handle, "playerObject_release"));
        funcs.emplace("playerObject_getByID", findFunc(handle, "playerObject_getByID"));
        funcs.emplace("playerObject_setDrawDistance", findFunc(handle, "playerObject_setDrawDistance"));
        funcs.emplace("playerObject_getDrawDistance", findFunc(handle, "playerObject_getDrawDistance"));
        funcs.emplace("playerObject_setModel", findFunc(handle, "playerObject_setModel"));
        funcs.emplace("playerObject_getModel", findFunc(handle, "playerObject_getModel"));
        funcs.emplace("playerObject_setCameraCollision", findFunc(handle, "playerObject_setCameraCollision"));
        funcs.emplace("playerObject_getCameraCollision", findFunc(handle, "playerObject_getCameraCollision"));
        funcs.emplace("playerObject_move", findFunc(handle, "playerObject_move"));
        funcs.emplace("playerObject_isMoving", findFunc(handle, "playerObject_isMoving"));
        funcs.emplace("playerObject_stop", findFunc(handle, "playerObject_stop"));
        funcs.emplace("playerObject_getMovingData", findFunc(handle, "playerObject_getMovingData"));
        funcs.emplace("playerObject_attachToVehicle", findFunc(handle, "playerObject_attachToVehicle"));
        funcs.emplace("playerObject_resetAttachment", findFunc(handle, "playerObject_resetAttachment"));
        funcs.emplace("playerObject_getAttachmentData", findFunc(handle, "playerObject_getAttachmentData"));
        funcs.emplace("playerObject_isMaterialSlotUsed", findFunc(handle, "playerObject_isMaterialSlotUsed"));
        funcs.emplace("playerObject_getMaterial", findFunc(handle, "playerObject_getMaterial"));
        funcs.emplace("playerObject_getMaterialText", findFunc(handle, "playerObject_getMaterialText"));
        funcs.emplace("playerObject_setMaterial", findFunc(handle, "playerObject_setMaterial"));
        funcs.emplace("playerObject_setMaterialText", findFunc(handle, "playerObject_setMaterialText"));
        funcs.emplace("playerObject_attachToPlayer", findFunc(handle, "playerObject_attachToPlayer"));
        funcs.emplace("playerObject_attachToObject", findFunc(handle, "playerObject_attachToObject"));
        funcs.emplace("playerObject_setPosition", findFunc(handle, "playerObject_setPosition"));
        funcs.emplace("playerObject_getPosition", findFunc(handle, "playerObject_getPosition"));
        funcs.emplace("playerObject_setRotation", findFunc(handle, "playerObject_setRotation"));
        funcs.emplace("playerObject_getRotation", findFunc(handle, "playerObject_getRotation"));

        // Player
        funcs.emplace("player_getByID", findFunc(handle, "player_getByID"));
        funcs.emplace("player_getID", findFunc(handle, "player_getID"));
        funcs.emplace("player_kick", findFunc(handle, "player_kick"));
        funcs.emplace("player_ban", findFunc(handle, "player_ban"));
        funcs.emplace("player_isBot", findFunc(handle, "player_isBot"));
        funcs.emplace("player_getPing", findFunc(handle, "player_getPing"));
        funcs.emplace("player_spawn", findFunc(handle, "player_spawn"));
        funcs.emplace("player_isSpawned", findFunc(handle, "player_isSpawned"));
        funcs.emplace("player_getClientVersion", findFunc(handle, "player_getClientVersion"));
        funcs.emplace("player_getClientVersionName", findFunc(handle, "player_getClientVersionName"));
        funcs.emplace("player_setPositionFindZ", findFunc(handle, "player_setPositionFindZ"));
        funcs.emplace("player_setCameraPosition", findFunc(handle, "player_setCameraPosition"));
        funcs.emplace("player_getCameraPosition", findFunc(handle, "player_getCameraPosition"));
        funcs.emplace("player_setCameraLookAt", findFunc(handle, "player_setCameraLookAt"));
        funcs.emplace("player_getCameraLookAt", findFunc(handle, "player_getCameraLookAt"));
        funcs.emplace("player_setCameraBehind", findFunc(handle, "player_setCameraBehind"));
        funcs.emplace("player_interpolateCameraPosition", findFunc(handle, "player_interpolateCameraPosition"));
        funcs.emplace("player_interpolateCameraLookAt", findFunc(handle, "player_interpolateCameraLookAt"));
        funcs.emplace("player_attachCameraToObject", findFunc(handle, "player_attachCameraToObject"));
        funcs.emplace("player_setName", findFunc(handle, "player_setName"));
        funcs.emplace("player_getName", findFunc(handle, "player_getName"));
        funcs.emplace("player_getSerial", findFunc(handle, "player_getSerial"));
        funcs.emplace("player_giveWeapon", findFunc(handle, "player_giveWeapon"));
        funcs.emplace("player_removeWeapon", findFunc(handle, "player_removeWeapon"));
        funcs.emplace("player_setWeaponAmmo", findFunc(handle, "player_setWeaponAmmo"));
        funcs.emplace("player_getWeapons", findFunc(handle, "player_getWeapons"));
        funcs.emplace("player_getWeaponSlot", findFunc(handle, "player_getWeaponSlot"));
        funcs.emplace("player_resetWeapons", findFunc(handle, "player_resetWeapons"));
        funcs.emplace("player_setArmedWeapon", findFunc(handle, "player_setArmedWeapon"));
        funcs.emplace("player_getArmedWeapon", findFunc(handle, "player_getArmedWeapon"));
        funcs.emplace("player_getArmedWeaponAmmo", findFunc(handle, "player_getArmedWeaponAmmo"));
        funcs.emplace("player_setShopName", findFunc(handle, "player_setShopName"));
        funcs.emplace("player_getShopName", findFunc(handle, "player_getShopName"));
        funcs.emplace("player_setDrunkLevel", findFunc(handle, "player_setDrunkLevel"));
        funcs.emplace("player_getDrunkLevel", findFunc(handle, "player_getDrunkLevel"));
        funcs.emplace("player_setColour", findFunc(handle, "player_setColour"));
        funcs.emplace("player_getColour", findFunc(handle, "player_getColour"));
        funcs.emplace("player_setOtherColour", findFunc(handle, "player_setOtherColour"));
        funcs.emplace("player_getOtherColour", findFunc(handle, "player_getOtherColour"));
        funcs.emplace("player_setControllable", findFunc(handle, "player_setControllable"));
        funcs.emplace("player_getControllable", findFunc(handle, "player_getControllable"));
        funcs.emplace("player_setSpectating", findFunc(handle, "player_setSpectating"));
        funcs.emplace("player_setWantedLevel", findFunc(handle, "player_setWantedLevel"));
        funcs.emplace("player_getWantedLevel", findFunc(handle, "player_getWantedLevel"));
        funcs.emplace("player_playSound", findFunc(handle, "player_playSound"));
        funcs.emplace("player_lastPlayedSound", findFunc(handle, "player_lastPlayedSound"));
        funcs.emplace("player_playAudio", findFunc(handle, "player_playAudio"));
        funcs.emplace("player_playerCrimeReport", findFunc(handle, "player_playerCrimeReport"));
        funcs.emplace("player_stopAudio", findFunc(handle, "player_stopAudio"));
        funcs.emplace("player_lastPlayedAudio", findFunc(handle, "player_lastPlayedAudio"));
        funcs.emplace("player_createExplosion", findFunc(handle, "player_createExplosion"));
        funcs.emplace("player_sendDeathMessage", findFunc(handle, "player_sendDeathMessage"));
        funcs.emplace("player_sendEmptyDeathMessage", findFunc(handle, "player_sendEmptyDeathMessage"));
        funcs.emplace("player_removeDefaultObjects", findFunc(handle, "player_removeDefaultObjects"));
        funcs.emplace("player_forceClassSelection", findFunc(handle, "player_forceClassSelection"));
        funcs.emplace("player_setMoney", findFunc(handle, "player_setMoney"));
        funcs.emplace("player_giveMoney", findFunc(handle, "player_giveMoney"));
        funcs.emplace("player_resetMoney", findFunc(handle, "player_resetMoney"));
        funcs.emplace("player_getMoney", findFunc(handle, "player_getMoney"));
        funcs.emplace("player_setMapIcon", findFunc(handle, "player_setMapIcon"));
        funcs.emplace("player_unsetMapIcon", findFunc(handle, "player_unsetMapIcon"));
        funcs.emplace("player_useStuntBonuses", findFunc(handle, "player_useStuntBonuses"));
        funcs.emplace("player_toggleOtherNameTag", findFunc(handle, "player_toggleOtherNameTag"));
        funcs.emplace("player_setTime", findFunc(handle, "player_setTime"));
        funcs.emplace("player_getTime", findFunc(handle, "player_getTime"));
        funcs.emplace("player_useClock", findFunc(handle, "player_useClock"));
        funcs.emplace("player_useWidescreen", findFunc(handle, "player_useWidescreen"));
        funcs.emplace("player_hasWidescreen", findFunc(handle, "player_hasWidescreen"));
        funcs.emplace("player_setHealth", findFunc(handle, "player_setHealth"));
        funcs.emplace("player_getHealth", findFunc(handle, "player_getHealth"));
        funcs.emplace("player_setScore", findFunc(handle, "player_setScore"));
        funcs.emplace("player_getScore", findFunc(handle, "player_getScore"));
        funcs.emplace("player_setArmour", findFunc(handle, "player_setArmour"));
        funcs.emplace("player_getArmour", findFunc(handle, "player_getArmour"));
        funcs.emplace("player_setGravity", findFunc(handle, "player_setGravity"));
        funcs.emplace("player_getGravity", findFunc(handle, "player_getGravity"));
        funcs.emplace("player_setWorldTime", findFunc(handle, "player_setWorldTime"));
        funcs.emplace("player_applyAnimation", findFunc(handle, "player_applyAnimation"));
        funcs.emplace("player_clearAnimations", findFunc(handle, "player_clearAnimations"));
        funcs.emplace("player_getAnimationData", findFunc(handle, "player_getAnimationData"));
        funcs.emplace("player_isStreamedInForPlayer", findFunc(handle, "player_isStreamedInForPlayer"));
        funcs.emplace("player_getState", findFunc(handle, "player_getState"));
        funcs.emplace("player_setTeam", findFunc(handle, "player_setTeam"));
        funcs.emplace("player_getTeam", findFunc(handle, "player_getTeam"));
        funcs.emplace("player_setSkin", findFunc(handle, "player_setSkin"));
        funcs.emplace("player_getSkin", findFunc(handle, "player_getSkin"));
        funcs.emplace("player_setChatBubble", findFunc(handle, "player_setChatBubble"));
        funcs.emplace("player_sendClientMessage", findFunc(handle, "player_sendClientMessage"));
        funcs.emplace("player_sendChatMessage", findFunc(handle, "player_sendChatMessage"));
        funcs.emplace("player_sendCommand", findFunc(handle, "player_sendCommand"));
        funcs.emplace("player_sendGameText", findFunc(handle, "player_sendGameText"));
        funcs.emplace("player_hideGameText", findFunc(handle, "player_hideGameText"));
        funcs.emplace("player_hasGameText", findFunc(handle, "player_hasGameText"));
        funcs.emplace("player_getGameText", findFunc(handle, "player_getGameText"));
        funcs.emplace("player_setWeather", findFunc(handle, "player_setWeather"));
        funcs.emplace("player_getWeather", findFunc(handle, "player_getWeather"));
        funcs.emplace("player_setWorldBounds", findFunc(handle, "player_setWorldBounds"));
        funcs.emplace("player_getWorldBounds", findFunc(handle, "player_getWorldBounds"));
        funcs.emplace("player_setFightingStyle", findFunc(handle, "player_setFightingStyle"));
        funcs.emplace("player_getFightingStyle", findFunc(handle, "player_getFightingStyle"));
        funcs.emplace("player_setSkillLevel", findFunc(handle, "player_setSkillLevel"));
        funcs.emplace("player_setAction", findFunc(handle, "player_setAction"));
        funcs.emplace("player_getAction", findFunc(handle, "player_getAction"));
        funcs.emplace("player_setVelocity", findFunc(handle, "player_setVelocity"));
        funcs.emplace("player_getVelocity", findFunc(handle, "player_getVelocity"));
        funcs.emplace("player_setInterior", findFunc(handle, "player_setInterior"));
        funcs.emplace("player_getInterior", findFunc(handle, "player_getInterior"));
        funcs.emplace("player_getKeyData", findFunc(handle, "player_getKeyData"));
        funcs.emplace("player_getAimData", findFunc(handle, "player_getAimData"));
        funcs.emplace("player_getBulletData", findFunc(handle, "player_getBulletData"));
        funcs.emplace("player_useCameraTargeting", findFunc(handle, "player_useCameraTargeting"));
        funcs.emplace("player_hasCameraTargeting", findFunc(handle, "player_hasCameraTargeting"));
        funcs.emplace("player_removeFromVehicle", findFunc(handle, "player_removeFromVehicle"));
        funcs.emplace("player_getCameraTargetPlayer", findFunc(handle, "player_getCameraTargetPlayer"));
        funcs.emplace("player_getCameraTargetVehicle", findFunc(handle, "player_getCameraTargetVehicle"));
        funcs.emplace("player_getCameraTargetObject", findFunc(handle, "player_getCameraTargetObject"));
        funcs.emplace("player_getCameraTargetActor", findFunc(handle, "player_getCameraTargetActor"));
        funcs.emplace("player_getTargetPlayer", findFunc(handle, "player_getTargetPlayer"));
        funcs.emplace("player_getTargetActor", findFunc(handle, "player_getTargetActor"));
        funcs.emplace("player_setRemoteVehicleCollisions", findFunc(handle, "player_setRemoteVehicleCollisions"));
        funcs.emplace("player_spectatePlayer", findFunc(handle, "player_spectatePlayer"));
        funcs.emplace("player_spectateVehicle", findFunc(handle, "player_spectateVehicle"));
        funcs.emplace("player_getSpectateData", findFunc(handle, "player_getSpectateData"));
        funcs.emplace("player_sendClientCheck", findFunc(handle, "player_sendClientCheck"));
        funcs.emplace("player_toggleGhostMode", findFunc(handle, "player_toggleGhostMode"));
        funcs.emplace("player_isGhostModeEnabled", findFunc(handle, "player_isGhostModeEnabled"));
        funcs.emplace("player_getDefaultObjectsRemoved", findFunc(handle, "player_getDefaultObjectsRemoved"));
        funcs.emplace("player_getKickStatus", findFunc(handle, "player_getKickStatus"));
        funcs.emplace("player_clearTasks", findFunc(handle, "player_clearTasks"));
        funcs.emplace("player_allowWeapons", findFunc(handle, "player_allowWeapons"));
        funcs.emplace("player_areWeaponsAllowed", findFunc(handle, "player_areWeaponsAllowed"));
        funcs.emplace("player_allowTeleport", findFunc(handle, "player_allowTeleport"));
        funcs.emplace("player_isTeleportAllowed", findFunc(handle, "player_isTeleportAllowed"));
        funcs.emplace("player_isUsingOfficialClient", findFunc(handle, "player_isUsingOfficialClient"));

        funcs.emplace("player_setPosition", findFunc(handle, "player_setPosition"));
        funcs.emplace("player_getPosition", findFunc(handle, "player_getPosition"));
        funcs.emplace("player_getRotation", findFunc(handle, "player_getRotation"));
        funcs.emplace("player_setVirtualWorld", findFunc(handle, "player_setVirtualWorld"));
        funcs.emplace("player_getVirtualWorld", findFunc(handle, "player_getVirtualWorld"));

        funcs.emplace("player_setCheckpoint", findFunc(handle, "player_setCheckpoint"));

        funcs.emplace("player_setConsoleAccessibility", findFunc(handle, "player_setConsoleAccessibility"));
        funcs.emplace("player_hasConsoleAccess", findFunc(handle, "player_hasConsoleAccess"));

        funcs.emplace("player_getCheckpoint", findFunc(handle, "player_getCheckpoint"));
        funcs.emplace("player_getRaceCheckpoint", findFunc(handle, "player_getRaceCheckpoint"));

        funcs.emplace("player_getCustomSkin", findFunc(handle, "player_getCustomSkin"));

        funcs.emplace("player_getIp", findFunc(handle, "player_getIp"));
        funcs.emplace("player_getRawIp", findFunc(handle, "player_getRawIp"));

        funcs.emplace("player_getVehicle", findFunc(handle, "player_getVehicle"));
        funcs.emplace("player_getSeat", findFunc(handle, "player_getSeat"));
        funcs.emplace("player_isInModShop", findFunc(handle, "player_isInModShop"));

        funcs.emplace("player_beginObjectEditing", findFunc(handle, "player_beginObjectEditing"));
        funcs.emplace("player_endObjectEditing", findFunc(handle, "player_endObjectEditing"));
        funcs.emplace("player_isEditingObject", findFunc(handle, "player_isEditingObject"));
        funcs.emplace("player_beginObjectSelecting", findFunc(handle, "player_beginObjectSelecting"));
        funcs.emplace("player_isSelectingObject", findFunc(handle, "player_isSelectingObject"));
        funcs.emplace("player_setAttachedObject", findFunc(handle, "player_setAttachedObject"));
        funcs.emplace("player_getAttachedObject", findFunc(handle, "player_getAttachedObject"));
        funcs.emplace("player_removeAttachedObject", findFunc(handle, "player_removeAttachedObject"));
        funcs.emplace("player_editAttachedObject", findFunc(handle, "player_editAttachedObject"));
        funcs.emplace("player_hasAttachedObject", findFunc(handle, "player_hasAttachedObject"));

        funcs.emplace("player_getDistanceFromPoint", findFunc(handle, "player_getDistanceFromPoint"));
        funcs.emplace("player_isInRangeOfPoint", findFunc(handle, "player_isInRangeOfPoint"));
        funcs.emplace("player_setFacingAngle", findFunc(handle, "player_setFacingAngle"));
        funcs.emplace("player_getFacingAngle", findFunc(handle, "player_getFacingAngle"));

        // Vehicle
        funcs.emplace("vehicle_create", findFunc(handle, "vehicle_create"));
        funcs.emplace("vehicle_release", findFunc(handle, "vehicle_release"));
        funcs.emplace("vehicle_getByID", findFunc(handle, "vehicle_getByID"));
        funcs.emplace("vehicle_isStreamedInForPlayer", findFunc(handle, "vehicle_isStreamedInForPlayer"));
        funcs.emplace("vehicle_setColour", findFunc(handle, "vehicle_setColour"));
        funcs.emplace("vehicle_getColour", findFunc(handle, "vehicle_getColour"));
        funcs.emplace("vehicle_setHealth", findFunc(handle, "vehicle_setHealth"));
        funcs.emplace("vehicle_getHealth", findFunc(handle, "vehicle_getHealth"));
        funcs.emplace("vehicle_getDriver", findFunc(handle, "vehicle_getDriver"));
        funcs.emplace("vehicle_getPassengers", findFunc(handle, "vehicle_getPassengers"));
        funcs.emplace("vehicle_setPlate", findFunc(handle, "vehicle_setPlate"));
        funcs.emplace("vehicle_getPlate", findFunc(handle, "vehicle_getPlate"));
        funcs.emplace("vehicle_setDamageStatus", findFunc(handle, "vehicle_setDamageStatus"));
        funcs.emplace("vehicle_getDamageStatus", findFunc(handle, "vehicle_getDamageStatus"));
        funcs.emplace("vehicle_setPaintjob", findFunc(handle, "vehicle_setPaintjob"));
        funcs.emplace("vehicle_getPaintjob", findFunc(handle, "vehicle_getPaintjob"));
        funcs.emplace("vehicle_addComponent", findFunc(handle, "vehicle_addComponent"));
        funcs.emplace("vehicle_getComponentInSlot", findFunc(handle, "vehicle_getComponentInSlot"));
        funcs.emplace("vehicle_removeComponent", findFunc(handle, "vehicle_removeComponent"));
        funcs.emplace("vehicle_putPlayer", findFunc(handle, "vehicle_putPlayer"));
        funcs.emplace("vehicle_setZAngle", findFunc(handle, "vehicle_setZAngle"));
        funcs.emplace("vehicle_getZAngle", findFunc(handle, "vehicle_getZAngle"));
        funcs.emplace("vehicle_setParams", findFunc(handle, "vehicle_setParams"));
        funcs.emplace("vehicle_setParamsForPlayer", findFunc(handle, "vehicle_setParamsForPlayer"));
        funcs.emplace("vehicle_getParams", findFunc(handle, "vehicle_getParams"));
        funcs.emplace("vehicle_isDead", findFunc(handle, "vehicle_isDead"));
        funcs.emplace("vehicle_respawn", findFunc(handle, "vehicle_respawn"));
        funcs.emplace("vehicle_setRespawnDelay", findFunc(handle, "vehicle_setRespawnDelay"));
        funcs.emplace("vehicle_getRespawnDelay", findFunc(handle, "vehicle_getRespawnDelay"));
        funcs.emplace("vehicle_isRespawning", findFunc(handle, "vehicle_isRespawning"));
        funcs.emplace("vehicle_setInterior", findFunc(handle, "vehicle_setInterior"));
        funcs.emplace("vehicle_getInterior", findFunc(handle, "vehicle_getInterior"));
        funcs.emplace("vehicle_attachTrailer", findFunc(handle, "vehicle_attachTrailer"));
        funcs.emplace("vehicle_detachTrailer", findFunc(handle, "vehicle_detachTrailer"));
        funcs.emplace("vehicle_isTrailer", findFunc(handle, "vehicle_isTrailer"));
        funcs.emplace("vehicle_getTrailer", findFunc(handle, "vehicle_getTrailer"));
        funcs.emplace("vehicle_getCab", findFunc(handle, "vehicle_getCab"));
        funcs.emplace("vehicle_repair", findFunc(handle, "vehicle_repair"));
        funcs.emplace("vehicle_setVelocity", findFunc(handle, "vehicle_setVelocity"));
        funcs.emplace("vehicle_getVelocity", findFunc(handle, "vehicle_getVelocity"));
        funcs.emplace("vehicle_setAngularVelocity", findFunc(handle, "vehicle_setAngularVelocity"));
        funcs.emplace("vehicle_getAngularVelocity", findFunc(handle, "vehicle_getAngularVelocity"));
        funcs.emplace("vehicle_getModel", findFunc(handle, "vehicle_getModel"));
        funcs.emplace("vehicle_getLandingGearState", findFunc(handle, "vehicle_getLandingGearState"));
        funcs.emplace("vehicle_hasBeenOccupied", findFunc(handle, "vehicle_hasBeenOccupied"));
        funcs.emplace("vehicle_getLastOccupiedTime", findFunc(handle, "vehicle_getLastOccupiedTime"));
        funcs.emplace("vehicle_getLastSpawnTime", findFunc(handle, "vehicle_getLastSpawnTime"));
        funcs.emplace("vehicle_isOccupied", findFunc(handle, "vehicle_isOccupied"));
        funcs.emplace("vehicle_setSiren", findFunc(handle, "vehicle_setSiren"));
        funcs.emplace("vehicle_getSirenState", findFunc(handle, "vehicle_getSirenState"));
        funcs.emplace("vehicle_getHydraThrustAngle", findFunc(handle, "vehicle_getHydraThrustAngle"));
        funcs.emplace("vehicle_getTrainSpeed", findFunc(handle, "vehicle_getTrainSpeed"));
        funcs.emplace("vehicle_getLastDriverPoolID", findFunc(handle, "vehicle_getLastDriverPoolID"));

        funcs.emplace("vehicle_setPosition", findFunc(handle, "vehicle_setPosition"));
        funcs.emplace("vehicle_getPosition", findFunc(handle, "vehicle_getPosition"));
        funcs.emplace("vehicle_getRotation", findFunc(handle, "vehicle_getRotation"));

        funcs.emplace("vehicle_getDistanceFromPoint", findFunc(handle, "vehicle_getDistanceFromPoint"));
        funcs.emplace("vehicle_isInRangeOfPoint", findFunc(handle, "vehicle_isInRangeOfPoint"));

        funcs.emplace("pickup_create", findFunc(handle, "pickup_create"));
        funcs.emplace("pickup_release", findFunc(handle, "pickup_release"));
        funcs.emplace("pickup_getID", findFunc(handle, "pickup_getID"));
        funcs.emplace("pickup_setType", findFunc(handle, "pickup_setType"));
        funcs.emplace("pickup_getType", findFunc(handle, "pickup_getType"));
        funcs.emplace("pickup_setModel", findFunc(handle, "pickup_setModel"));
        funcs.emplace("pickup_getModel", findFunc(handle, "pickup_getModel"));
        funcs.emplace("pickup_isStreamedInForPlayer", findFunc(handle, "pickup_isStreamedInForPlayer"));
        funcs.emplace("pickup_setPickupHiddenForPlayer", findFunc(handle, "pickup_setPickupHiddenForPlayer"));
        funcs.emplace("pickup_isPickupHiddenForPlayer", findFunc(handle, "pickup_isPickupHiddenForPlayer"));

        funcs.emplace("pickup_setPosition", findFunc(handle, "pickup_setPosition"));
        funcs.emplace("pickup_getPosition", findFunc(handle, "pickup_getPosition"));
        funcs.emplace("pickup_setVirtualWorld", findFunc(handle, "pickup_setVirtualWorld"));
        funcs.emplace("pickup_getVirtualWorld", findFunc(handle, "pickup_getVirtualWorld"));

        funcs.emplace("playerPickup_create", findFunc(handle, "playerPickup_create"));
        funcs.emplace("playerPickup_release", findFunc(handle, "playerPickup_release"));

        // TextDraw
        funcs.emplace("textDraw_create", findFunc(handle, "textDraw_create"));
        funcs.emplace("textDraw_release", findFunc(handle, "textDraw_release"));
        funcs.emplace("textDraw_getID", findFunc(handle, "textDraw_getID"));
        funcs.emplace("textDraw_setPosition", findFunc(handle, "textDraw_setPosition"));
        funcs.emplace("textDraw_getPosition", findFunc(handle, "textDraw_getPosition"));
        funcs.emplace("textDraw_setText", findFunc(handle, "textDraw_setText"));
        funcs.emplace("textDraw_getText", findFunc(handle, "textDraw_getText"));
        funcs.emplace("textDraw_setLetterSize", findFunc(handle, "textDraw_setLetterSize"));
        funcs.emplace("textDraw_getLetterSize", findFunc(handle, "textDraw_getLetterSize"));
        funcs.emplace("textDraw_setTextSize", findFunc(handle, "textDraw_setTextSize"));
        funcs.emplace("textDraw_getTextSize", findFunc(handle, "textDraw_getTextSize"));
        funcs.emplace("textDraw_setAlignment", findFunc(handle, "textDraw_setAlignment"));
        funcs.emplace("textDraw_getAlignment", findFunc(handle, "textDraw_getAlignment"));
        funcs.emplace("textDraw_setColour", findFunc(handle, "textDraw_setColour"));
        funcs.emplace("textDraw_getLetterColour", findFunc(handle, "textDraw_getLetterColour"));
        funcs.emplace("textDraw_useBox", findFunc(handle, "textDraw_useBox"));
        funcs.emplace("textDraw_hasBox", findFunc(handle, "textDraw_hasBox"));
        funcs.emplace("textDraw_setBoxColour", findFunc(handle, "textDraw_setBoxColour"));
        funcs.emplace("textDraw_getBoxColour", findFunc(handle, "textDraw_getBoxColour"));
        funcs.emplace("textDraw_setShadow", findFunc(handle, "textDraw_setShadow"));
        funcs.emplace("textDraw_getShadow", findFunc(handle, "textDraw_getShadow"));
        funcs.emplace("textDraw_setOutline", findFunc(handle, "textDraw_setOutline"));
        funcs.emplace("textDraw_getOutline", findFunc(handle, "textDraw_getOutline"));
        funcs.emplace("textDraw_setBackgroundColour", findFunc(handle, "textDraw_setBackgroundColour"));
        funcs.emplace("textDraw_getBackgroundColour", findFunc(handle, "textDraw_getBackgroundColour"));
        funcs.emplace("textDraw_setStyle", findFunc(handle, "textDraw_setStyle"));
        funcs.emplace("textDraw_getStyle", findFunc(handle, "textDraw_getStyle"));
        funcs.emplace("textDraw_setProportional", findFunc(handle, "textDraw_setProportional"));
        funcs.emplace("textDraw_isProportional", findFunc(handle, "textDraw_isProportional"));
        funcs.emplace("textDraw_setSelectable", findFunc(handle, "textDraw_setSelectable"));
        funcs.emplace("textDraw_isSelectable", findFunc(handle, "textDraw_isSelectable"));
        funcs.emplace("textDraw_setPreviewModel", findFunc(handle, "textDraw_setPreviewModel"));
        funcs.emplace("textDraw_getPreviewModel", findFunc(handle, "textDraw_getPreviewModel"));
        funcs.emplace("textDraw_setPreviewRotation", findFunc(handle, "textDraw_setPreviewRotation"));
        funcs.emplace("textDraw_getPreviewRotation", findFunc(handle, "textDraw_getPreviewRotation"));
        funcs.emplace("textDraw_setPreviewVehicleColour", findFunc(handle, "textDraw_setPreviewVehicleColour"));
        funcs.emplace("textDraw_getPreviewVehicleColour", findFunc(handle, "textDraw_getPreviewVehicleColour"));
        funcs.emplace("textDraw_setPreviewZoom", findFunc(handle, "textDraw_setPreviewZoom"));
        funcs.emplace("textDraw_getPreviewZoom", findFunc(handle, "textDraw_getPreviewZoom"));
        funcs.emplace("textDraw_showForPlayer", findFunc(handle, "textDraw_showForPlayer"));
        funcs.emplace("textDraw_hideForPlayer", findFunc(handle, "textDraw_hideForPlayer"));
        funcs.emplace("textDraw_isShownForPlayer", findFunc(handle, "textDraw_isShownForPlayer"));
        funcs.emplace("textDraw_setTextForPlayer", findFunc(handle, "textDraw_setTextForPlayer"));

        // PlayeTextDraw
        funcs.emplace("playerTextDraw_create", findFunc(handle, "playerTextDraw_create"));
        funcs.emplace("playerTextDraw_release", findFunc(handle, "playerTextDraw_release"));
        funcs.emplace("playerTextDraw_getID", findFunc(handle, "playerTextDraw_getID"));
        funcs.emplace("playerTextDraw_setPosition", findFunc(handle, "playerTextDraw_setPosition"));
        funcs.emplace("playerTextDraw_getPosition", findFunc(handle, "playerTextDraw_getPosition"));
        funcs.emplace("playerTextDraw_setText", findFunc(handle, "playerTextDraw_setText"));
        funcs.emplace("playerTextDraw_getText", findFunc(handle, "playerTextDraw_getText"));
        funcs.emplace("playerTextDraw_setLetterSize", findFunc(handle, "playerTextDraw_setLetterSize"));
        funcs.emplace("playerTextDraw_getLetterSize", findFunc(handle, "playerTextDraw_getLetterSize"));
        funcs.emplace("playerTextDraw_setTextSize", findFunc(handle, "playerTextDraw_setTextSize"));
        funcs.emplace("playerTextDraw_getTextSize", findFunc(handle, "playerTextDraw_getTextSize"));
        funcs.emplace("playerTextDraw_setAlignment", findFunc(handle, "playerTextDraw_setAlignment"));
        funcs.emplace("playerTextDraw_getAlignment", findFunc(handle, "playerTextDraw_getAlignment"));
        funcs.emplace("playerTextDraw_setColour", findFunc(handle, "playerTextDraw_setColour"));
        funcs.emplace("playerTextDraw_getLetterColour", findFunc(handle, "playerTextDraw_getLetterColour"));
        funcs.emplace("playerTextDraw_useBox", findFunc(handle, "playerTextDraw_useBox"));
        funcs.emplace("playerTextDraw_hasBox", findFunc(handle, "playerTextDraw_hasBox"));
        funcs.emplace("playerTextDraw_setBoxColour", findFunc(handle, "playerTextDraw_setBoxColour"));
        funcs.emplace("playerTextDraw_getBoxColour", findFunc(handle, "playerTextDraw_getBoxColour"));
        funcs.emplace("playerTextDraw_setShadow", findFunc(handle, "playerTextDraw_setShadow"));
        funcs.emplace("playerTextDraw_getShadow", findFunc(handle, "playerTextDraw_getShadow"));
        funcs.emplace("playerTextDraw_setOutline", findFunc(handle, "playerTextDraw_setOutline"));
        funcs.emplace("playerTextDraw_getOutline", findFunc(handle, "playerTextDraw_getOutline"));
        funcs.emplace("playerTextDraw_setBackgroundColour", findFunc(handle, "playerTextDraw_setBackgroundColour"));
        funcs.emplace("playerTextDraw_getBackgroundColour", findFunc(handle, "playerTextDraw_getBackgroundColour"));
        funcs.emplace("playerTextDraw_setStyle", findFunc(handle, "playerTextDraw_setStyle"));
        funcs.emplace("playerTextDraw_getStyle", findFunc(handle, "playerTextDraw_getStyle"));
        funcs.emplace("playerTextDraw_setProportional", findFunc(handle, "playerTextDraw_setProportional"));
        funcs.emplace("playerTextDraw_isProportional", findFunc(handle, "playerTextDraw_isProportional"));
        funcs.emplace("playerTextDraw_setSelectable", findFunc(handle, "playerTextDraw_setSelectable"));
        funcs.emplace("playerTextDraw_isSelectable", findFunc(handle, "playerTextDraw_isSelectable"));
        funcs.emplace("playerTextDraw_setPreviewModel", findFunc(handle, "playerTextDraw_setPreviewModel"));
        funcs.emplace("playerTextDraw_getPreviewModel", findFunc(handle, "playerTextDraw_getPreviewModel"));
        funcs.emplace("playerTextDraw_setPreviewRotation", findFunc(handle, "playerTextDraw_setPreviewRotation"));
        funcs.emplace("playerTextDraw_getPreviewRotation", findFunc(handle, "playerTextDraw_getPreviewRotation"));
        funcs.emplace("playerTextDraw_setPreviewVehicleColour", findFunc(handle, "playerTextDraw_setPreviewVehicleColour"));
        funcs.emplace("playerTextDraw_getPreviewVehicleColour", findFunc(handle, "playerTextDraw_getPreviewVehicleColour"));
        funcs.emplace("playerTextDraw_setPreviewZoom", findFunc(handle, "playerTextDraw_setPreviewZoom"));
        funcs.emplace("playerTextDraw_getPreviewZoom", findFunc(handle, "playerTextDraw_getPreviewZoom"));
        funcs.emplace("playerTextDraw_show", findFunc(handle, "playerTextDraw_show"));
        funcs.emplace("playerTextDraw_hide", findFunc(handle, "playerTextDraw_hide"));
        funcs.emplace("playerTextDraw_isShown", findFunc(handle, "playerTextDraw_isShown"));
    
        // TextLabel
        funcs.emplace("textLabel_create", findFunc(handle, "textLabel_create"));
        funcs.emplace("textLabel_release", findFunc(handle, "textLabel_release"));
        funcs.emplace("textLabel_setText", findFunc(handle, "textLabel_setText"));
        funcs.emplace("textLabel_getText", findFunc(handle, "textLabel_getText"));
        funcs.emplace("textLabel_setColour", findFunc(handle, "textLabel_setColour"));
        funcs.emplace("textLabel_getColour", findFunc(handle, "textLabel_getColour"));
        funcs.emplace("textLabel_setDrawDistance", findFunc(handle, "textLabel_setDrawDistance"));
        funcs.emplace("textLabel_getDrawDistance", findFunc(handle, "textLabel_getDrawDistance"));
        funcs.emplace("textLabel_attachToPlayer", findFunc(handle, "textLabel_attachToPlayer"));
        funcs.emplace("textLabel_attachToVehicle", findFunc(handle, "textLabel_attachToVehicle"));
        funcs.emplace("textLabel_getAttachmentData", findFunc(handle, "textLabel_getAttachmentData"));
        funcs.emplace("textLabel_detachFromPlayer", findFunc(handle, "textLabel_detachFromPlayer"));
        funcs.emplace("textLabel_detachFromVehicle", findFunc(handle, "textLabel_detachFromVehicle"));
        funcs.emplace("textLabel_setTestLOS", findFunc(handle, "textLabel_setTestLOS"));
        funcs.emplace("textLabel_getTestLOS", findFunc(handle, "textLabel_getTestLOS"));
        funcs.emplace("textLabel_isStreamedInForPlayer", findFunc(handle, "textLabel_isStreamedInForPlayer"));
        funcs.emplace("textLabel_setPosition", findFunc(handle, "textLabel_setPosition"));
        funcs.emplace("textLabel_getPosition", findFunc(handle, "textLabel_getPosition"));
        funcs.emplace("textLabel_setVirtualWorld", findFunc(handle, "textLabel_setVirtualWorld"));
        funcs.emplace("textLabel_getVirtualWorld", findFunc(handle, "textLabel_getVirtualWorld"));
    }

    void freeArray(Array* arr)
    {
        return call<void>("freeArray", arr);
    }

#ifdef __cplusplus
}
#endif
