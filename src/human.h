/*
                               Human Preset Data
 */

#ifndef HUMAN_H
#define HUMAN_H

#include <sys/types.h>
#include "obj.h"		/* For SAR_HUMAN_COLOR_* definations */


/*
 *	Human Presets Data Entry:
 */
typedef struct {

	char		*name;

	/* Weight in kg */
	float		mass;

	/* Height in meters */
	float		height;

	/* Color palette */
	sar_color_struct	color[SAR_HUMAN_COLORS_MAX];

	/* Number of assisting humans (0 for none) */
	int		assisting_humans;

	/* Assisting human color palette */
	sar_color_struct	assisting_human_color[SAR_HUMAN_COLORS_MAX];

} sar_human_data_entry_struct;
#define SAR_HUMAN_DATA_ENTRY(p)	((sar_human_data_entry_struct *)(p))


/*
 *	Human Data Presets:
 */
typedef struct {

	void		*core_ptr;

	sar_human_data_entry_struct	**preset;
	int				total_presets;

} sar_human_data_struct;
#define SAR_HUMAN_DATA(p)	((sar_human_data_struct *)(p))


/* In human.c */
extern sar_human_data_entry_struct *SARHumanMatchEntryByName(
	sar_human_data_struct *hd, const char *name
);

extern sar_human_data_struct *SARHumanPresetsInit(void *core_ptr);
extern void SARHumanPresetsShutdown(sar_human_data_struct *hd);

extern void SARHumanEntryDelete(
	sar_human_data_struct *hd, sar_human_data_entry_struct *entry
);
extern int SARHumanCreate(
	sar_human_data_struct *hd,
	sar_scene_struct *scene,
	sar_object_struct ***object, int *total_objects,
	sar_obj_flags_t human_flags,
	const char *name
);
extern void SARHumanSetObjectPreset(
	sar_human_data_struct *hd,
	sar_object_struct *obj_ptr,
	const char *name
);

/* In humanio.c */
extern int SARHumanLoadFromFile(
	sar_human_data_struct *w,
	const char *filename
);


#endif	/* HUMAN_H */
