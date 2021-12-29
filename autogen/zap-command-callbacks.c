/*******************************************************************************
 * @file  zap-command-callbacks.c
 * @brief This file contains weak implementations for the ZCL cluster callbacks
 * that the user must implement in the current project. Weak implementations are
 * supplied in order to allow the project to compile.
 * When generating this file ZAP uses the info from implementedCommands.json  
 * to determine which ZCL commands have an SDK implementation. 
 * 
 * This file is generated. Do not update the file manually.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "sl_component_catalog.h"
#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT

#include "af.h"
#include "zap-type.h"

/* The ZCL cluster command callbacks should have a proper (not WEAK) implementation in a
 * separate file in the project, the current file will be overwritten with every subsequent
 * project generation.
 */
WEAK(bool emberAfColorControlClusterColorLoopSetCallback(uint8_t updateFlags , uint8_t action , uint8_t direction , uint16_t time , uint16_t startHue , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterEnhancedMoveHueCallback(uint8_t moveMode , uint16_t rate , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterEnhancedMoveToHueCallback(uint16_t enhancedHue , uint8_t direction , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterEnhancedMoveToHueAndSaturationCallback(uint16_t enhancedHue , uint8_t saturation , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterEnhancedStepHueCallback(uint8_t stepMode , uint16_t stepSize , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterMoveColorTemperatureCallback(uint8_t moveMode , uint16_t rate , uint16_t colorTemperatureMinimum , uint16_t colorTemperatureMaximum , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterMoveToColorTemperatureCallback(uint16_t colorTemperature , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterStepColorTemperatureCallback(uint8_t stepMode , uint16_t stepSize , uint16_t transitionTime , uint16_t colorTemperatureMinimum , uint16_t colorTemperatureMaximum , uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfColorControlClusterStopMoveStepCallback(uint8_t optionsMask , uint8_t optionsOverride )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfGroupsClusterAddGroupCallback(uint16_t groupId , uint8_t * groupName )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfIdentifyClusterTriggerEffectCallback(uint8_t effectId , uint8_t effectVariant )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfScenesClusterAddSceneCallback(uint16_t groupId , uint8_t sceneId , uint16_t transitionTime , uint8_t * sceneName , /* TYPE WARNING: SceneExtensionFieldSet array defaults to */ uint8_t * extensionFieldSets )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterDeviceInformationRequestCallback(uint32_t transaction , uint8_t startIndex )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterIdentifyRequestCallback(uint32_t transaction , uint16_t identifyDuration )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterNetworkJoinEndDeviceRequestCallback(uint32_t transaction , uint8_t * extendedPanId , uint8_t keyIndex , /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey , uint8_t networkUpdateId , uint8_t logicalChannel , uint16_t panId , uint16_t networkAddress , uint16_t groupIdentifiersBegin , uint16_t groupIdentifiersEnd , uint16_t freeNetworkAddressRangeBegin , uint16_t freeNetworkAddressRangeEnd , uint16_t freeGroupIdentifierRangeBegin , uint16_t freeGroupIdentifierRangeEnd )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterNetworkJoinRouterRequestCallback(uint32_t transaction , uint8_t * extendedPanId , uint8_t keyIndex , /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey , uint8_t networkUpdateId , uint8_t logicalChannel , uint16_t panId , uint16_t networkAddress , uint16_t groupIdentifiersBegin , uint16_t groupIdentifiersEnd , uint16_t freeNetworkAddressRangeBegin , uint16_t freeNetworkAddressRangeEnd , uint16_t freeGroupIdentifierRangeBegin , uint16_t freeGroupIdentifierRangeEnd )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterNetworkStartRequestCallback(uint32_t transaction , uint8_t * extendedPanId , uint8_t keyIndex , /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey , uint8_t logicalChannel , uint16_t panId , uint16_t networkAddress , uint16_t groupIdentifiersBegin , uint16_t groupIdentifiersEnd , uint16_t freeNetworkAddressRangeBegin , uint16_t freeNetworkAddressRangeEnd , uint16_t freeGroupIdentifierRangeBegin , uint16_t freeGroupIdentifierRangeEnd , uint8_t * initiatorIeeeAddress , uint16_t initiatorNetworkAddress )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterNetworkUpdateRequestCallback(uint32_t transaction , uint8_t * extendedPanId , uint8_t networkUpdateId , uint8_t logicalChannel , uint16_t panId , uint16_t networkAddress )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterResetToFactoryNewRequestCallback(uint32_t transaction )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfZllCommissioningClusterScanRequestCallback(uint32_t transaction , uint8_t zigbeeInformation , uint8_t zllInformation )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}


/* For reference purposes below is the list of ZCL cluster command callbacks in this project that have an SDK implementation.
 * The implementation will be visible if the corresonding component gets included in the project. */ 
// bool emberAfColorControlClusterMoveColorCallback(int16_t rateX , int16_t rateY , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveHueCallback(uint8_t moveMode , uint8_t rate , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveSaturationCallback(uint8_t moveMode , uint8_t rate , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveToColorCallback(uint16_t colorX , uint16_t colorY , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveToHueCallback(uint8_t hue , uint8_t direction , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveToHueAndSaturationCallback(uint8_t hue , uint8_t saturation , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterMoveToSaturationCallback(uint8_t saturation , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterStepColorCallback(int16_t stepX , int16_t stepY , uint16_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterStepHueCallback(uint8_t stepMode , uint8_t stepSize , uint8_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfColorControlClusterStepSaturationCallback(uint8_t stepMode , uint8_t stepSize , uint8_t transitionTime , uint8_t optionsMask , uint8_t optionsOverride );

// bool emberAfGroupsClusterAddGroupIfIdentifyingCallback(uint16_t groupId , uint8_t * groupName );

// bool emberAfGroupsClusterGetGroupMembershipCallback(uint8_t groupCount , /* TYPE WARNING: INT16U array defaults to */ uint8_t * groupList );

// bool emberAfGroupsClusterRemoveAllGroupsCallback();

// bool emberAfGroupsClusterRemoveGroupCallback(uint16_t groupId );

// bool emberAfGroupsClusterViewGroupCallback(uint16_t groupId );

// bool emberAfIdentifyClusterIdentifyCallback(uint16_t identifyTime );

// bool emberAfIdentifyClusterIdentifyQueryCallback();

// bool emberAfLevelControlClusterMoveCallback(uint8_t moveMode , uint8_t rate , uint8_t optionMask , uint8_t optionOverride );

// bool emberAfLevelControlClusterMoveToLevelCallback(uint8_t level , uint16_t transitionTime , uint8_t optionMask , uint8_t optionOverride );

// bool emberAfLevelControlClusterMoveToLevelWithOnOffCallback(uint8_t level , uint16_t transitionTime );

// bool emberAfLevelControlClusterMoveWithOnOffCallback(uint8_t moveMode , uint8_t rate );

// bool emberAfLevelControlClusterStepCallback(uint8_t stepMode , uint8_t stepSize , uint16_t transitionTime , uint8_t optionMask , uint8_t optionOverride );

// bool emberAfLevelControlClusterStepWithOnOffCallback(uint8_t stepMode , uint8_t stepSize , uint16_t transitionTime );

// bool emberAfLevelControlClusterStopCallback(uint8_t optionMask , uint8_t optionOverride );

// bool emberAfLevelControlClusterStopWithOnOffCallback();

// bool emberAfOnOffClusterOffCallback();

// bool emberAfOnOffClusterOffWithEffectCallback(uint8_t effectId , uint8_t effectVariant );

// bool emberAfOnOffClusterOnCallback();

// bool emberAfOnOffClusterOnWithRecallGlobalSceneCallback();

// bool emberAfOnOffClusterOnWithTimedOffCallback(uint8_t onOffControl , uint16_t onTime , uint16_t offWaitTime );

// bool emberAfOnOffClusterToggleCallback();

// bool emberAfScenesClusterCopySceneCallback(uint8_t mode , uint16_t groupIdFrom , uint8_t sceneIdFrom , uint16_t groupIdTo , uint8_t sceneIdTo );

// bool emberAfScenesClusterEnhancedAddSceneCallback(uint16_t groupId , uint8_t sceneId , uint16_t transitionTime , uint8_t * sceneName , /* TYPE WARNING: SceneExtensionFieldSet array defaults to */ uint8_t * extensionFieldSets );

// bool emberAfScenesClusterEnhancedViewSceneCallback(uint16_t groupId , uint8_t sceneId );

// bool emberAfScenesClusterGetSceneMembershipCallback(uint16_t groupId );

// bool emberAfScenesClusterRecallSceneCallback(uint16_t groupId , uint8_t sceneId , uint16_t transitionTime );

// bool emberAfScenesClusterRemoveAllScenesCallback(uint16_t groupId );

// bool emberAfScenesClusterRemoveSceneCallback(uint16_t groupId , uint8_t sceneId );

// bool emberAfScenesClusterStoreSceneCallback(uint16_t groupId , uint8_t sceneId );

// bool emberAfScenesClusterViewSceneCallback(uint16_t groupId , uint8_t sceneId );

// bool emberAfZllCommissioningClusterGetEndpointListRequestCallback(uint8_t startIndex );

// bool emberAfZllCommissioningClusterGetGroupIdentifiersRequestCallback(uint8_t startIndex );



#endif
