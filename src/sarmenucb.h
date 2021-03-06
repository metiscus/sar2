/**********************************************************************
*   This file is part of Search and Rescue II (SaR2).                 *
*                                                                     *
*   SaR2 is free software: you can redistribute it and/or modify      *
*   it under the terms of the GNU General Public License v.2 as       *
*   published by the Free Software Foundation.                        *
*                                                                     *
*   SaR2 is distributed in the hope that it will be useful, but       *
*   WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See          *
*   the GNU General Public License for more details.                  *
*                                                                     *
*   You should have received a copy of the GNU General Public License *
*   along with SaR2.  If not, see <http://www.gnu.org/licenses/>.     *
***********************************************************************/

#ifndef SARMENUCB_H
#define SARMENUCB_H

#include "gw.h"
#include "menu.h"
#include "sar.h"

extern void SARMenuButtonCB(void *object, int id_code, void *client_data);
extern void SARMenuListSelectCB(
        void *object, int id_code, void *client_data,
        int item_num, void *item_ptr, void *item_data
);
extern void SARMenuListActivateCB(
        void *object, int id_code, void *client_data,
        int item_num, void *item_ptr, void *item_data
);
extern void SARMenuSwitchCB(
	void *object, int id_code, void *client_data,
	Boolean state
);
extern void SARMenuSpinCB(
	void *object, int id_code, void *client_data,
	char *value
);

#endif	/* SARMENUCB_H */
