#include "parson.h"
//----------------------------------------------------------------


    
    //----------------------------------------------------------------
    //                              BEGIN   
    //                   *** INIT GLOBAL VARIABLES ***
    //----------------------------------------------------------------

    extern JSON_Value *schema;
    extern JSON_Value *user_data ;
    
    

    //----------------------------------------------------------------
    // Tilesets
    //----------------------------------------------------------------
    extern JSON_Array *tilesets_array ; 
    extern struct tilesets{
        int count;
        const char *identifier;
        int uid;
        const char *relPath;
        int pxWid;
        int pxHei;
        int tileGridSize;
        int spacing;
        int padding;
    } tilesets;

    //----------------------------------------------------------------

    //----------------------------------------------------------------
    // Enums
    //----------------------------------------------------------------
    extern JSON_Array *enums_array;
    extern JSON_Array *enums_values;
    extern JSON_Array *enums_externalEnums;
    extern JSON_Array *enums_tileSrcRec;
    extern struct enums_details{
        const char *id;
        int tileId;
        int tileSrcRec[4];
    } enums_details;

    extern struct enums{
        const char *identifier;
        int uid;
        int iconTilesetUid;
        struct enums_details *enums_details_ptr;
    } enums, *enums_details_ptr;
    //----------------------------------------------------------------

    

    
    //----------------------------------------------------------------
    //intGrid
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances_intGrid;
    extern JSON_Array *levels_layerInstances_intGrid_results ;
    extern struct integerGrid{
        int count;
        int coordId; //Where on the map the tile is located
        int v;       //The type of collision tile
    } integerGrid;
    //----------------------------------------------------------------
    
    //----------------------------------------------------------------
    //autoTiles
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances_autoTiles;
    extern JSON_Array *levels_layerInstances_autoTiles_results;
    extern JSON_Array *levels_layerInstances_autoTiles_results_tiles ;
    extern struct autoTiles{
        int count;
        int x;
        int y;
        int SRCx;
        int SRCy;
        int f;
    } autoTiles;
    //----------------------------------------------------------------

    //----------------------------------------------------------------
    //gridTiles
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances_gridTiles;
    extern JSON_Array *levels_layerInstances_gridTiles_results;
    //extern JSON_Array *levels_layerInstances_gridTiles_results_tiles ; unused?
    extern struct gridTiles{
        int count;
        int x;
        int y;
        int SRCx;
        int SRCy;
        int f;
    } gridTiles;
    //----------------------------------------------------------------

    
    //----------------------------------------------------------------
    //fieldInstances
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances_entityInstances_fieldInstances;

    extern JSON_Array *levels_layerInstances_entityInstances_fieldInstances_value;
    extern JSON_Array *levels_layerInstances_entityInstances_fieldInstances_realEditorValues;
    extern JSON_Array *levels_layerInstances_entityInstances_fieldInstances_realEditorValues_params;

    extern JSON_Object *levels_layerInstances_entityInstances_fieldInstances_object;

    //points
    extern struct fieldInstances_points{
        int cx;
        int cy;
        signed char check; //Cheat check to handle NULL values until I find a better way
        int size;
    } fieldInstances_points;

    //Used with:
    //floats
    extern struct fieldInstances_floats{
        float floatValue;
        signed char check; //Cheat check to handle NULL values until I find a better way
        int size;
    } fieldInstances_floats;

    //Used with:
    //ints, bools
    extern struct fieldInstances_ints{
        int intValue;
        signed char check; //Cheat check to handle NULL values until I find a better way
        int size;
    } fieldInstances_ints;


    //Used with:
    // strings, multilines, colors, items, filepaths
    extern struct fieldInstances_strings{
        const char *strValue;
        signed char check; //Cheat check to handle NULL values until I find a better way
        int size;
    } fieldInstances_strings;

    extern struct fieldInstances_tiles{
        int tilesetUid;
        int x,y,w,h;
        signed char check; //Cheat check to handle NULL values until I find a better way
        int size;
    } fieldInstances_tiles;


    extern struct fieldInstances{
        const char *identifier;
        const char *type;
        struct fieldInstances_points *fieldInstances_points_ptr;
        struct fieldInstances_floats *fieldInstances_floats_ptr;
        struct fieldInstances_ints *fieldInstances_ints_ptr;
        struct fieldInstances_strings *fieldInstances_strings_ptr;
        struct fieldInstances_tiles *fieldInstances_tiles_ptr;
        int defUid;
        int size;
    } fieldInstances,*fieldInstances_details_ptr, *fieldInstances_points_ptr, *fieldInstances_floats_ptr, *fieldInstances_ints_ptr,*fieldInstances_strings_ptr;
    //----------------------------------------------------------------

    //----------------------------------------------------------------
    //entityInstances
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances_entityInstances;
    extern struct entityInstances{
        const char *identifier;
        int cx;
        int cy;
        int x;
        int y;
        int defUid;
        int size;
        int fieldInstanceCount;
        struct fieldInstances *fieldInstances_data_ptr;
    } entityInstances, *entityInstances_details_ptr, *fieldInstances_data_ptr;
    //----------------------------------------------------------------

    
    //----------------------------------------------------------------
    //layerInstances
    //----------------------------------------------------------------
    extern JSON_Array *levels_layerInstances;
    extern JSON_Array *levels_layerInstances_gridTiles ;
    extern struct layerInstances{
        const char *identifier;
        const char *type;
        int cWid;
        int cHei;
        int gridSize;
        int levelId;
        int layerDefUid;
        int pxOffsetX;
        int pxOffsetY;
        struct autoTiles *autoTiles_data_ptr;
        struct gridTiles *gridTiles_data_ptr;
        struct entityInstances *entityInstances_data_ptr;
        int numEntityInstancesDataPtr;
        struct integerGrid  *integerGrid_data_ptr;
        int *intGrid;

    } layerInstances,*layerInstances_details_ptr, *autoTiles_data_ptr,*gridTiles_data_ptr, *entityInstances_data_ptr,*integerGrid_data_ptr;
    //----------------------------------------------------------------

    //----------------------------------------------------------------
    // Level Neighbors
    //----------------------------------------------------------------
    struct levelNeighbors {
        char dir;
        int uid;
    };

    //----------------------------------------------------------------
    // Levels
    //----------------------------------------------------------------
    extern JSON_Array *levels_array;
    extern JSON_Array *levels_neighbors;
    extern struct levels{
        const char *identifier;
        int uid;
        int pxWid;
        int pxHei;
        int worldX;
        int worldY;
        int firstIntFieldInst;
        struct levelNeighbors *neighbors;
        int numNeighbors;
        struct layerInstances *layers_data_ptr;
        struct tilesets *tilesets_data_ptr;
        struct enums *enums_data_ptr;    
    } levels,*levels_details_ptr, *layers_data_ptr,*tilesets_data_ptr,*enums_data_ptr;
    //----------------------------------------------------------------

    //----------------------------------------------------------------
    // File specs
    //----------------------------------------------------------------
    extern struct file_detail{
        const char *jsonVersion;
        double defaultPivotX;
        double defaultPivotY;
        int defaultGridSize;
        const char *bgColor;
        int nextUid;
        struct levels *levels_data_ptr; 
    } file_detail,*file_details_ptr,*levels_data_ptr;

#ifdef _WIN32
#define UNUSED(x) x
#else
#define UNUSED(x) x __attribute__((unused))
#endif // 


    //Used for strcmp
    //single value checks
    static const char * UNUSED(fieldInstance_integer) = "Int";
    static const char * UNUSED(fieldInstance_float) = "Float";
    static const char * UNUSED(fieldInstance_boolean) = "Bool";
    static const char * UNUSED(fieldInstance_string) = "String";
    static const char * UNUSED(fieldInstance_localEnum) = "LocalEnum"; //9 chars
    static const char * UNUSED(fieldInstance_color) = "Color";
    static const char * UNUSED(fieldInstance_point) = "Point";
    static const char * UNUSED(fieldInstance_filePath) = "FilePath";
    //array value checks
    static const char * UNUSED(fieldInstance_array_int) = "Array<Int>";
    static const char * UNUSED(fieldInstance_array_float) = "Array<Float>";
    static const char * UNUSED(fieldInstance_array_boolean) = "Array<Bool>";
    static const char * UNUSED(fieldInstance_array_string) = "Array<String>";
    static const char * UNUSED(fieldInstance_array_localEnum) = "Array<LocalEnum"; //15 chars
    static const char * UNUSED(fieldInstance_array_point) = "Array<Point>";
    static const char * UNUSED(fieldInstance_array_color) = "Array<Color>";
    static const char * UNUSED(fieldInstance_array_filePath) = "Array<FilePath>";
    static const char * UNUSED(fieldInstance_array_tile) = "Array<Tile>";
    
    


    //----------------------------------------------------------------
    //                                END   
    //                   *** INIT GLOBAL VARIABLES ***
    //----------------------------------------------------------------


//----------------------------------------------------------------
//    *** ALL PRINT FUNCTIONS MUST BE CALLED AFTER DATA HAS BEEN LOADED ***
//----------------------------------------------------------------
#ifdef __cplusplus
extern "C"{
#endif

void importFileSpecs(void);
void importTilesetData(void);
void freeTilesetData(void);
void importEnumsData(void);
void freeEnumsData(void);
void importLevelsData(void);
void freeLevelsData(void);
struct levels* getLevel(char* levelName);
struct levels* getLevelFromUid(int levelId);
void getLevelNames(char** name_arr,int* len);
struct tilesets* getTilesets(int* out_len);
struct entityInstances* getEntity(char* entityName,int levelId);
struct layerInstances* getLayer(char* layerName,int levelId);
void getLayers(int levelUId,struct layerInstances** out,int* len);
void loadJSONFile(char* fileSchema,char* fileName);
void importMapData(void);
void freeMapData(void);

#ifdef __cplusplus
}
#endif