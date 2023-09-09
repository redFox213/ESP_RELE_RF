idf_component_register(SRCS "NimBLE.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_event
                    REQUIRES nvs_flash
                    REQUIRES bt) 
