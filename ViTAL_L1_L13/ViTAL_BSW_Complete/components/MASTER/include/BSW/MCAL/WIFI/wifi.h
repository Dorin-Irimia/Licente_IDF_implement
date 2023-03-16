
#ifndef COMPONENTS_VITAL_BSW_MCAL_WIFI_H
#define COMPONENTS_VITAL_BSW_MCAL_WIFI_H

#include "global.h"

/*
 * OBS!
 *
 * 1 - Password for WPA2-PSK should have a minimum of 8 chars
 * 2 - Do not use a while(1) loop; Use FreeRTOS system
 * 3 - Don't forget to set the max URI length to 1024
 * */

#include "esp_http_server.h"

esp_err_t WebPageGetHandler(httpd_req_t *req);

esp_err_t DataGetHandler(httpd_req_t *req);

esp_err_t WebPagePostHandler(httpd_req_t *req);

httpd_handle_t WebPageStart(void);

void WIFI_vInit(void *arg);

/* WIFI credentials */
#define ESP_SSID_AP "ViTAL_ESP8266_server"
#define ESP_PASS_AP "12345678"

#endif
