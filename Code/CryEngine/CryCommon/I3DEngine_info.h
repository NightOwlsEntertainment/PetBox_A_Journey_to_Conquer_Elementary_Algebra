#include <I3DEngine.h> // <> required for Interfuscator

STRUCT_INFO_BEGIN(STerrainInfo)
	STRUCT_VAR_INFO(nHeightMapSize_InUnits, TYPE_INFO(int))
	STRUCT_VAR_INFO(nUnitSize_InMeters, TYPE_INFO(int))
	STRUCT_VAR_INFO(nSectorSize_InMeters, TYPE_INFO(int))
	STRUCT_VAR_INFO(nSectorsTableSize_InSectors, TYPE_INFO(int))
	STRUCT_VAR_INFO(fHeightmapZRatio, TYPE_INFO(float))
	STRUCT_VAR_INFO(fOceanWaterLevel, TYPE_INFO(float))
STRUCT_INFO_END(STerrainInfo)

STRUCT_INFO_BEGIN(STerrainChunkHeader)
  STRUCT_VAR_INFO(nVersion, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nDummy, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nFlags, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nFlags2, TYPE_INFO(int8))
	STRUCT_VAR_INFO(nChunkSize, TYPE_INFO(int32))
	STRUCT_VAR_INFO(TerrainInfo, TYPE_INFO(STerrainInfo))
STRUCT_INFO_END(STerrainChunkHeader)

STRUCT_INFO_BEGIN(SVisAreaManChunkHeader)
  STRUCT_VAR_INFO(nVersion, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nDummy, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nFlags, TYPE_INFO(int8))
  STRUCT_VAR_INFO(nFlags2, TYPE_INFO(int8))
	STRUCT_VAR_INFO(nChunkSize, TYPE_INFO(int))
	STRUCT_VAR_INFO(nVisAreasNum, TYPE_INFO(int))
	STRUCT_VAR_INFO(nPortalsNum, TYPE_INFO(int))
	STRUCT_VAR_INFO(nOcclAreasNum, TYPE_INFO(int))
STRUCT_INFO_END(SVisAreaManChunkHeader)

STRUCT_INFO_BEGIN(SOcTreeNodeChunk)
	STRUCT_VAR_INFO(nChunkVersion, TYPE_INFO(int16))
  STRUCT_VAR_INFO(ucChildsMask, TYPE_INFO(int16))
	STRUCT_VAR_INFO(nodeBox, TYPE_INFO(AABB))
	STRUCT_VAR_INFO(nObjectsBlockSize, TYPE_INFO(int32))
STRUCT_INFO_END(SOcTreeNodeChunk)

STRUCT_INFO_BEGIN(SCommonFileHeader)
	STRUCT_VAR_INFO(signature, TYPE_ARRAY(4, TYPE_INFO(char)))
  STRUCT_VAR_INFO(file_type, TYPE_INFO(uint8))
  STRUCT_VAR_INFO(flags, TYPE_INFO(uint8))
	STRUCT_VAR_INFO(version, TYPE_INFO(uint16))
STRUCT_INFO_END(SCommonFileHeader)

STRUCT_INFO_BEGIN(SHotUpdateInfo)
  STRUCT_VAR_INFO(nHeigtmap, TYPE_INFO(uint32))
  STRUCT_VAR_INFO(nObjTypeMask, TYPE_INFO(uint32))
  STRUCT_VAR_INFO(areaBox, TYPE_INFO(AABB))
STRUCT_INFO_END(SHotUpdateInfo)

STRUCT_INFO_BEGIN(STerrainTextureFileHeader_old)
	STRUCT_VAR_INFO(nSectorSizeMeters, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(nLodsNum, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(nLayerCount, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(nReserved, TYPE_INFO(uint16))
STRUCT_INFO_END(STerrainTextureFileHeader_old)

STRUCT_INFO_BEGIN(STerrainTextureFileHeader)
	STRUCT_VAR_INFO(nLayerCount, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(dwFlags, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(fBrMultiplier, TYPE_INFO(float))
STRUCT_INFO_END(STerrainTextureFileHeader)

STRUCT_INFO_BEGIN(STerrainTextureLayerFileHeader)
	STRUCT_VAR_INFO(nSectorSizePixels, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(nReserved, TYPE_INFO(uint16))
	STRUCT_VAR_INFO(eTexFormat, TYPE_INFO(ETEX_Format))
	STRUCT_VAR_INFO(nSectorSizeBytes, TYPE_INFO(uint32))
STRUCT_INFO_END(STerrainTextureLayerFileHeader)

