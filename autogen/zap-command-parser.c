/***************************************************************************//**
 * @file  zap-command-parser.c
 * @brief This file contains a set of generated functions that parse the
 * incomming message, and call appropriate command handler.
 * This file is generated. Do not update file manually.
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

#include <stdint.h>

#include "af.h"
#include "zap-type.h"
#include "zap-command-parser.h"

EmberAfStatus emberAfColorControlClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfGroupsClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfIdentifyClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfLevelControlClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfScenesClusterServerCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfZllCommissioningClusterServerCommandParse(EmberAfClusterCommand * cmd);
extern uint16_t emberAfFindClusterNameIndexWithMfgCode(uint16_t cluster, uint16_t mfgCode);

static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
  if (wasHandled) {
    return EMBER_ZCL_STATUS_SUCCESS;
  } else if (clusterExists) {
    return EMBER_ZCL_STATUS_UNSUP_COMMAND;
  } else {
    return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
  }
}


// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand * cmd)
{
    EmberAfStatus result = status(false, false, cmd->mfgSpecific);
    if (cmd->direction == (uint8_t) ZCL_DIRECTION_SERVER_TO_CLIENT &&
        emberAfContainsClientWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
        default:
            // Unrecognized cluster ID, error status will apply.
            if (emberAfFindClusterNameIndexWithMfgCode(cmd->apsFrame->clusterId, cmd->mfgCode) != 0xFFFF) {
                result = status(false, true, cmd->mfgSpecific);
            }
            break;
        }
    }
    else if (cmd->direction == (uint8_t) ZCL_DIRECTION_CLIENT_TO_SERVER &&
             emberAfContainsServerWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
                case ZCL_COLOR_CONTROL_CLUSTER_ID :
                    result = emberAfColorControlClusterServerCommandParse(cmd);
                    break;
                case ZCL_GROUPS_CLUSTER_ID :
                    result = emberAfGroupsClusterServerCommandParse(cmd);
                    break;
                case ZCL_IDENTIFY_CLUSTER_ID :
                    result = emberAfIdentifyClusterServerCommandParse(cmd);
                    break;
                case ZCL_LEVEL_CONTROL_CLUSTER_ID :
                    result = emberAfLevelControlClusterServerCommandParse(cmd);
                    break;
                case ZCL_ON_OFF_CLUSTER_ID :
                    result = emberAfOnOffClusterServerCommandParse(cmd);
                    break;
                case ZCL_SCENES_CLUSTER_ID :
                    result = emberAfScenesClusterServerCommandParse(cmd);
                    break;
                case ZCL_ZLL_COMMISSIONING_CLUSTER_ID :
                    result = emberAfZllCommissioningClusterServerCommandParse(cmd);
                    break;
        default:
            // Unrecognized cluster ID, error status will apply.
            if (emberAfFindClusterNameIndexWithMfgCode(cmd->apsFrame->clusterId, cmd->mfgCode) != 0xFFFF) {
                result = status(false, true, cmd->mfgSpecific);
            }
            break;
        }
    }
    return result;
}

// Cluster specific command parsing

EmberAfStatus emberAfColorControlClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_COLOR_LOOP_SET_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t updateFlags;
                uint8_t action;
                uint8_t direction;
                uint16_t time;
                uint16_t startHue;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
updateFlags = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
action = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
direction = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
time = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
startHue = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterColorLoopSetCallback(updateFlags, action, direction, time, startHue, optionsMask, optionsOverride);
            break;
        }
            case ZCL_ENHANCED_MOVE_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t moveMode;
                uint16_t rate;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rate = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterEnhancedMoveHueCallback(moveMode, rate, optionsMask, optionsOverride);
            break;
        }
            case ZCL_ENHANCED_MOVE_TO_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t enhancedHue;
                uint8_t direction;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
enhancedHue = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
direction = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterEnhancedMoveToHueCallback(enhancedHue, direction, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_ENHANCED_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t enhancedHue;
                uint8_t saturation;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
enhancedHue = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
saturation = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterEnhancedMoveToHueAndSaturationCallback(enhancedHue, saturation, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_ENHANCED_STEP_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t stepMode;
                uint16_t stepSize;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepSize = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterEnhancedStepHueCallback(stepMode, stepSize, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_COLOR_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                int16_t rateX;
                int16_t rateY;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rateX = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rateY = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveColorCallback(rateX, rateY, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_COLOR_TEMPERATURE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t moveMode;
                uint16_t rate;
                uint16_t colorTemperatureMinimum;
                uint16_t colorTemperatureMaximum;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rate = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorTemperatureMinimum = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorTemperatureMaximum = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveColorTemperatureCallback(moveMode, rate, colorTemperatureMinimum, colorTemperatureMaximum, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t moveMode;
                uint8_t rate;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveHueCallback(moveMode, rate, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_SATURATION_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t moveMode;
                uint8_t rate;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveSaturationCallback(moveMode, rate, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_TO_COLOR_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t colorX;
                uint16_t colorY;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorX = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorY = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveToColorCallback(colorX, colorY, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_TO_COLOR_TEMPERATURE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t colorTemperature;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorTemperature = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveToColorTemperatureCallback(colorTemperature, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_TO_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t hue;
                uint8_t direction;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
hue = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
direction = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveToHueCallback(hue, direction, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t hue;
                uint8_t saturation;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
hue = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
saturation = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveToHueAndSaturationCallback(hue, saturation, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_MOVE_TO_SATURATION_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t saturation;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
saturation = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterMoveToSaturationCallback(saturation, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_STEP_COLOR_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                int16_t stepX;
                int16_t stepY;
                uint16_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepX = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepY = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterStepColorCallback(stepX, stepY, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_STEP_COLOR_TEMPERATURE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t stepMode;
                uint16_t stepSize;
                uint16_t transitionTime;
                uint16_t colorTemperatureMinimum;
                uint16_t colorTemperatureMaximum;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepSize = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorTemperatureMinimum = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
colorTemperatureMaximum = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterStepColorTemperatureCallback(stepMode, stepSize, transitionTime, colorTemperatureMinimum, colorTemperatureMaximum, optionsMask, optionsOverride);
            break;
        }
            case ZCL_STEP_HUE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t stepMode;
                uint8_t stepSize;
                uint8_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterStepHueCallback(stepMode, stepSize, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_STEP_SATURATION_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t stepMode;
                uint8_t stepSize;
                uint8_t transitionTime;
                uint8_t optionsMask;
                uint8_t optionsOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterStepSaturationCallback(stepMode, stepSize, transitionTime, optionsMask, optionsOverride);
            break;
        }
            case ZCL_STOP_MOVE_STEP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t optionsMask;
                uint8_t optionsOverride;
                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsMask =0xFF;
            } else {
optionsMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionsOverride =0xFF;
            } else {
optionsOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfColorControlClusterStopMoveStepCallback(optionsMask, optionsOverride);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfGroupsClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_ADD_GROUP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t groupId;
                uint8_t * groupName;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfGroupsClusterAddGroupCallback(groupId, groupName);
            break;
        }
            case ZCL_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t groupId;
                uint8_t * groupName;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfGroupsClusterAddGroupIfIdentifyingCallback(groupId, groupName);
            break;
        }
            case ZCL_GET_GROUP_MEMBERSHIP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t groupCount;
                /* TYPE WARNING: INT16U array defaults to */ uint8_t * groupList;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupCount = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

            groupList = cmd->buffer + payloadOffset;

            wasHandled = emberAfGroupsClusterGetGroupMembershipCallback(groupCount, groupList);
            break;
        }
            case ZCL_REMOVE_ALL_GROUPS_COMMAND_ID:
            { 

            wasHandled = emberAfGroupsClusterRemoveAllGroupsCallback();
            break;
        }
            case ZCL_REMOVE_GROUP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfGroupsClusterRemoveGroupCallback(groupId);
            break;
        }
            case ZCL_VIEW_GROUP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfGroupsClusterViewGroupCallback(groupId);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfIdentifyClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_IDENTIFY_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t identifyTime;
identifyTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfIdentifyClusterIdentifyCallback(identifyTime);
            break;
        }
            case ZCL_IDENTIFY_QUERY_COMMAND_ID:
            { 

            wasHandled = emberAfIdentifyClusterIdentifyQueryCallback();
            break;
        }
            case ZCL_TRIGGER_EFFECT_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t effectId;
                uint8_t effectVariant;
effectId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

effectVariant = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfIdentifyClusterTriggerEffectCallback(effectId, effectVariant);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfLevelControlClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_MOVE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t moveMode;
                uint8_t rate;
                uint8_t optionMask;
                uint8_t optionOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionMask =0xFF;
            } else {
optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionOverride =0xFF;
            } else {
optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfLevelControlClusterMoveCallback(moveMode, rate, optionMask, optionOverride);
            break;
        }
            case ZCL_MOVE_TO_LEVEL_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t level;
                uint16_t transitionTime;
                uint8_t optionMask;
                uint8_t optionOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
level = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionMask =0xFF;
            } else {
optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionOverride =0xFF;
            } else {
optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfLevelControlClusterMoveToLevelCallback(level, transitionTime, optionMask, optionOverride);
            break;
        }
            case ZCL_MOVE_TO_LEVEL_WITH_ON_OFF_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 3u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t level;
                uint16_t transitionTime;
level = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfLevelControlClusterMoveToLevelWithOnOffCallback(level, transitionTime);
            break;
        }
            case ZCL_MOVE_WITH_ON_OFF_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t moveMode;
                uint8_t rate;
moveMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

rate = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfLevelControlClusterMoveWithOnOffCallback(moveMode, rate);
            break;
        }
            case ZCL_STEP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t stepMode;
                uint8_t stepSize;
                uint16_t transitionTime;
                uint8_t optionMask;
                uint8_t optionOverride;
                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionMask =0xFF;
            } else {
optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionOverride =0xFF;
            } else {
optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfLevelControlClusterStepCallback(stepMode, stepSize, transitionTime, optionMask, optionOverride);
            break;
        }
            case ZCL_STEP_WITH_ON_OFF_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t stepMode;
                uint8_t stepSize;
                uint16_t transitionTime;
stepMode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

stepSize = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfLevelControlClusterStepWithOnOffCallback(stepMode, stepSize, transitionTime);
            break;
        }
            case ZCL_STOP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint8_t optionMask;
                uint8_t optionOverride;
                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionMask =0xFF;
            } else {
optionMask = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;
}

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 1u)
             {
                optionOverride =0xFF;
            } else {
optionOverride = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfLevelControlClusterStopCallback(optionMask, optionOverride);
            break;
        }
            case ZCL_STOP_WITH_ON_OFF_COMMAND_ID:
            { 

            wasHandled = emberAfLevelControlClusterStopWithOnOffCallback();
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_OFF_COMMAND_ID:
            { 

            wasHandled = emberAfOnOffClusterOffCallback();
            break;
        }
            case ZCL_OFF_WITH_EFFECT_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t effectId;
                uint8_t effectVariant;
effectId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

effectVariant = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfOnOffClusterOffWithEffectCallback(effectId, effectVariant);
            break;
        }
            case ZCL_ON_COMMAND_ID:
            { 

            wasHandled = emberAfOnOffClusterOnCallback();
            break;
        }
            case ZCL_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID:
            { 

            wasHandled = emberAfOnOffClusterOnWithRecallGlobalSceneCallback();
            break;
        }
            case ZCL_ON_WITH_TIMED_OFF_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 5u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t onOffControl;
                uint16_t onTime;
                uint16_t offWaitTime;
onOffControl = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

onTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

offWaitTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfOnOffClusterOnWithTimedOffCallback(onOffControl, onTime, offWaitTime);
            break;
        }
            case ZCL_TOGGLE_COMMAND_ID:
            { 

            wasHandled = emberAfOnOffClusterToggleCallback();
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfScenesClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_ADD_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t groupId;
                uint8_t sceneId;
                uint16_t transitionTime;
                uint8_t * sceneName;
                /* TYPE WARNING: SceneExtensionFieldSet array defaults to */ uint8_t * extensionFieldSets;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
sceneName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= emberAfStringLength(cmd->buffer + payloadOffset) + 1u;

            extensionFieldSets = cmd->buffer + payloadOffset;

            wasHandled = emberAfScenesClusterAddSceneCallback(groupId, sceneId, transitionTime, sceneName, extensionFieldSets);
            break;
        }
            case ZCL_COPY_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 7u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t mode;
                uint16_t groupIdFrom;
                uint8_t sceneIdFrom;
                uint16_t groupIdTo;
                uint8_t sceneIdTo;
mode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

groupIdFrom = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneIdFrom = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

groupIdTo = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneIdTo = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterCopySceneCallback(mode, groupIdFrom, sceneIdFrom, groupIdTo, sceneIdTo);
            break;
        }
            case ZCL_ENHANCED_ADD_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t groupId;
                uint8_t sceneId;
                uint16_t transitionTime;
                uint8_t * sceneName;
                /* TYPE WARNING: SceneExtensionFieldSet array defaults to */ uint8_t * extensionFieldSets;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
sceneName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= emberAfStringLength(cmd->buffer + payloadOffset) + 1u;

            extensionFieldSets = cmd->buffer + payloadOffset;

            wasHandled = emberAfScenesClusterEnhancedAddSceneCallback(groupId, sceneId, transitionTime, sceneName, extensionFieldSets);
            break;
        }
            case ZCL_ENHANCED_VIEW_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 3u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
                uint8_t sceneId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterEnhancedViewSceneCallback(groupId, sceneId);
            break;
        }
            case ZCL_GET_SCENE_MEMBERSHIP_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterGetSceneMembershipCallback(groupId);
            break;
        }
            case ZCL_RECALL_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Not a fixed length command
                uint16_t groupId;
                uint8_t sceneId;
                uint16_t transitionTime;
                if (cmd->bufLen < payloadOffset + 2u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

                if (cmd->bufLen < payloadOffset + 1u)
             {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }
sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

                // - Argument is not present in all versions.
                if (cmd->bufLen < payloadOffset + 2u)
             {
                transitionTime =0xFFFF;
            } else {
transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
}


            wasHandled = emberAfScenesClusterRecallSceneCallback(groupId, sceneId, transitionTime);
            break;
        }
            case ZCL_REMOVE_ALL_SCENES_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 2u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterRemoveAllScenesCallback(groupId);
            break;
        }
            case ZCL_REMOVE_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 3u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
                uint8_t sceneId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterRemoveSceneCallback(groupId, sceneId);
            break;
        }
            case ZCL_STORE_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 3u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
                uint8_t sceneId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterStoreSceneCallback(groupId, sceneId);
            break;
        }
            case ZCL_VIEW_SCENE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 3u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t groupId;
                uint8_t sceneId;
groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfScenesClusterViewSceneCallback(groupId, sceneId);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfZllCommissioningClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_DEVICE_INFORMATION_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 5u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t startIndex;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

startIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterDeviceInformationRequestCallback(transaction, startIndex);
            break;
        }
            case ZCL_GET_ENDPOINT_LIST_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t startIndex;
startIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterGetEndpointListRequestCallback(startIndex);
            break;
        }
            case ZCL_GET_GROUP_IDENTIFIERS_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 1u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t startIndex;
startIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterGetGroupIdentifiersRequestCallback(startIndex);
            break;
        }
            case ZCL_IDENTIFY_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 6u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint16_t identifyDuration;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

identifyDuration = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterIdentifyRequestCallback(transaction, identifyDuration);
            break;
        }
            case ZCL_NETWORK_JOIN_END_DEVICE_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 47u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t * extendedPanId;
                uint8_t keyIndex;
                /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey;
                uint8_t networkUpdateId;
                uint8_t logicalChannel;
                uint16_t panId;
                uint16_t networkAddress;
                uint16_t groupIdentifiersBegin;
                uint16_t groupIdentifiersEnd;
                uint16_t freeNetworkAddressRangeBegin;
                uint16_t freeNetworkAddressRangeEnd;
                uint16_t freeGroupIdentifierRangeBegin;
                uint16_t freeGroupIdentifierRangeEnd;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

extendedPanId = cmd->buffer + payloadOffset;
                payloadOffset+= 8u;

keyIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

encryptedNetworkKey = cmd->buffer + payloadOffset;
                payloadOffset+= 16u;

networkUpdateId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

logicalChannel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

panId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

networkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterNetworkJoinEndDeviceRequestCallback(transaction, extendedPanId, keyIndex, encryptedNetworkKey, networkUpdateId, logicalChannel, panId, networkAddress, groupIdentifiersBegin, groupIdentifiersEnd, freeNetworkAddressRangeBegin, freeNetworkAddressRangeEnd, freeGroupIdentifierRangeBegin, freeGroupIdentifierRangeEnd);
            break;
        }
            case ZCL_NETWORK_JOIN_ROUTER_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 47u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t * extendedPanId;
                uint8_t keyIndex;
                /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey;
                uint8_t networkUpdateId;
                uint8_t logicalChannel;
                uint16_t panId;
                uint16_t networkAddress;
                uint16_t groupIdentifiersBegin;
                uint16_t groupIdentifiersEnd;
                uint16_t freeNetworkAddressRangeBegin;
                uint16_t freeNetworkAddressRangeEnd;
                uint16_t freeGroupIdentifierRangeBegin;
                uint16_t freeGroupIdentifierRangeEnd;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

extendedPanId = cmd->buffer + payloadOffset;
                payloadOffset+= 8u;

keyIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

encryptedNetworkKey = cmd->buffer + payloadOffset;
                payloadOffset+= 16u;

networkUpdateId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

logicalChannel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

panId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

networkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterNetworkJoinRouterRequestCallback(transaction, extendedPanId, keyIndex, encryptedNetworkKey, networkUpdateId, logicalChannel, panId, networkAddress, groupIdentifiersBegin, groupIdentifiersEnd, freeNetworkAddressRangeBegin, freeNetworkAddressRangeEnd, freeGroupIdentifierRangeBegin, freeGroupIdentifierRangeEnd);
            break;
        }
            case ZCL_NETWORK_START_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 56u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t * extendedPanId;
                uint8_t keyIndex;
                /* TYPE WARNING: security_key defaults to */ uint8_t *  encryptedNetworkKey;
                uint8_t logicalChannel;
                uint16_t panId;
                uint16_t networkAddress;
                uint16_t groupIdentifiersBegin;
                uint16_t groupIdentifiersEnd;
                uint16_t freeNetworkAddressRangeBegin;
                uint16_t freeNetworkAddressRangeEnd;
                uint16_t freeGroupIdentifierRangeBegin;
                uint16_t freeGroupIdentifierRangeEnd;
                uint8_t * initiatorIeeeAddress;
                uint16_t initiatorNetworkAddress;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

extendedPanId = cmd->buffer + payloadOffset;
                payloadOffset+= 8u;

keyIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

encryptedNetworkKey = cmd->buffer + payloadOffset;
                payloadOffset+= 16u;

logicalChannel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

panId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

networkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

groupIdentifiersEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeNetworkAddressRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeBegin = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

freeGroupIdentifierRangeEnd = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

initiatorIeeeAddress = cmd->buffer + payloadOffset;
                payloadOffset+= 8u;

initiatorNetworkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterNetworkStartRequestCallback(transaction, extendedPanId, keyIndex, encryptedNetworkKey, logicalChannel, panId, networkAddress, groupIdentifiersBegin, groupIdentifiersEnd, freeNetworkAddressRangeBegin, freeNetworkAddressRangeEnd, freeGroupIdentifierRangeBegin, freeGroupIdentifierRangeEnd, initiatorIeeeAddress, initiatorNetworkAddress);
            break;
        }
            case ZCL_NETWORK_UPDATE_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 18u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t * extendedPanId;
                uint8_t networkUpdateId;
                uint8_t logicalChannel;
                uint16_t panId;
                uint16_t networkAddress;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

extendedPanId = cmd->buffer + payloadOffset;
                payloadOffset+= 8u;

networkUpdateId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

logicalChannel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

panId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

networkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterNetworkUpdateRequestCallback(transaction, extendedPanId, networkUpdateId, logicalChannel, panId, networkAddress);
            break;
        }
            case ZCL_RESET_TO_FACTORY_NEW_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterResetToFactoryNewRequestCallback(transaction);
            break;
        }
            case ZCL_SCAN_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 6u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint32_t transaction;
                uint8_t zigbeeInformation;
                uint8_t zllInformation;
transaction = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 4u;

zigbeeInformation = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

zllInformation = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfZllCommissioningClusterScanRequestCallback(transaction, zigbeeInformation, zllInformation);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}


#endif