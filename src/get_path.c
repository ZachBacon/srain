#include <glib.h>

#include "meta.h"
#include "log.h"

/**
 * @brief get_theme_path
 *
 * @param filename
 *
 * @return NULL or path to the theme file, must be freed.
 */
char *get_theme_path(const char *filename){
    char *path;

    path = g_build_filename(META_PACKAGE_DATA_DIRS, "share",
            META_PACKAGE_NAME, "themes", filename, NULL);

    if (g_file_test(path, G_FILE_TEST_EXISTS)){
        return path;
    }

    ERR_FR("'%s' not found", path);
    g_free(path);
    return NULL;
}

/**
 * @brief get_pixmap_path 
 *
 * @param filename
 *
 * @return NULL or path to the pixmap file, must be freed.
 */
char *get_pixmap_path(const char *filename){
    char *path;

    path = g_build_filename(META_PACKAGE_DATA_DIRS, "share",
            META_PACKAGE_NAME, "pixmaps", filename, NULL);

    if (g_file_test(path, G_FILE_TEST_EXISTS)){
        return path;
    }

    ERR_FR("'%s' not found", path);
    g_free(path);
    return NULL;
}

/**
 * @brief get_plugin_path
 *
 * @param filename
 *
 * @return 
 */
char *get_plugin_path(const char *filename){
    char *path;

    path = g_build_filename(META_PACKAGE_DATA_DIRS, "share",
            META_PACKAGE_NAME, "plugins", filename, NULL);

    if (g_file_test(path, G_FILE_TEST_EXISTS)){
        return path;
    }

    ERR_FR("'%s' not found", path);
    g_free(path);
    return NULL;
}

/**
 * @brief get_config_path
 *
 * @param filename
 *
 * @return 
 */
char *get_config_path(const char *filename){
    char *path;

    path = g_build_filename(".", filename, NULL);

    if (g_file_test(path, G_FILE_TEST_EXISTS)){
        return path;
    }
    ERR_FR("'%s' not found", path);
    g_free(path);

    path = g_build_filename(g_get_user_config_dir(), META_PACKAGE_NAME,
            filename, NULL);

    if (g_file_test(path, G_FILE_TEST_EXISTS)){
        return path;
    }

    ERR_FR("'%s' not found", path);
    g_free(path);
    return NULL;
}