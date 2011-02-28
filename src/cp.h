/*
			     Control Panel
 */

#ifndef CP_H
#define CP_H

#include <sys/types.h>
#include <GL/gl.h>
#include "gw.h"
#include "v3dtex.h"
#include "cpvalues.h"
#include "cpins.h"


/*
 *	Control Panel structure:
 */
typedef struct {

	gw_display_struct	*display;
	GLfloat	x, y, z;		/* In centimeters from center of
					 * cockpit.
					 */
	GLfloat heading, pitch, bank;	/* In radians. */
	GLfloat	width, height;		/* In centimeters. */
	v3d_texture_ref_struct	*tex;	/* Texture. */

	/* List of all instruments on this control panel. */
	CPIns	**ins;
	int	total_ins;

	ControlPanelValues	values;

} ControlPanel;
#define CONTROL_PANEL(p)	((ControlPanel *)(p))
#define CONTROL_PANEL_DISPLAY(p)	(((p) != NULL) ? \
 (CONTROL_PANEL(p)->display) : NULL)
#define CONTROL_PANEL_VALUES(p)		(((p) != NULL) ? \
 &(CONTROL_PANEL(p)->values) : NULL)


extern time_t CPCurrentTime(ControlPanel *cp);

extern CPIns *CPGetInsByNumber(ControlPanel *cp, int i);
extern int CPAppendIns(ControlPanel *cp, CPIns *ins);

extern ControlPanel *CPNew(gw_display_struct *display);
extern void CPDelete(ControlPanel *cp);

extern void CPSetPosition(
	ControlPanel *cp,
	GLfloat x, GLfloat y, GLfloat z /* In centimeters. */
);
extern void CPSetDirection(
	ControlPanel *cp,
	GLfloat heading, GLfloat pitch, GLfloat bank    /* In radians. */
);
extern void CPSetSize(
	ControlPanel *cp,
	GLfloat width, GLfloat height   /* In centimeters. */
);
extern void CPSetTexture(ControlPanel *cp, const char *path);

extern void CPResetTimmers(ControlPanel *cp, time_t t);
extern void CPChangeValues(ControlPanel *cp, ControlPanelValues *v);
extern void CPDraw(ControlPanel *cp);
extern void CPManage(ControlPanel *cp, ControlPanelValues *v);



#endif	/* CP_H */
