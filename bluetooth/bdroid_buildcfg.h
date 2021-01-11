/*
 * Copyright (C) 2012 The Android Open Source Project
 * Copyright (C) 2014 The CyanogenMod Project <http://www.cyanogenmod.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
int property_get(const char *key, char *value, const char *default_value);
#ifdef __cplusplus
}
#endif

static inline const char* BtmGetDefaultName()
{
    char product_device[92];
    property_get("ro.product.device", product_device, "");
    
    if (strstr(product_device, "starqltechn"))
        return "Galaxy S9";
    if (strstr(product_device, "starq2ltechn"))
        return "Galaxy S9+";
    if (strstr(product_device, "crownqltechn"))
        return "Galaxy Note 9";
    
    // Fallback to Default
    return "Samsung Galaxy";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
#define MAX_L2CAP_CHANNELS    32
#define GATT_MAX_PHY_CHANNEL  10
#define BTM_WBS_INCLUDED TRUE       /* Enable WBS */
#define BTIF_HF_WBS_PREFERRED FALSE /* Don't prefer WBS    */

#define BLE_VND_INCLUDED TRUE

#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE


#endif
