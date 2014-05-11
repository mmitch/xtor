/****************************************************************************
 * midiedit - GTK based editor for MIDI synthesizers
 *
 * controller.h - Interface to MIDI controllers.
 *
 * Copyright (C) 2014  Ricard Wanderlof <ricard2013@butoba.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ****************************************************************************/

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

enum controller_type { INCREMENTOR, POTENTIOMETER, BUTTON };

/* Callback for notifying UI of incoming parameter value changes */
typedef void (*controller_notify_cb)(int controller_number,
                                     enum controller_type controller_type,
                                     int delta, void *ref);

/* Struct for specifying controller-specific functions and values, intended
 * to be filled in by controller-specific initialization routines. */
struct controller {
  void (*controller_register_notify_cb)(controller_notify_cb cb, void *ref);

  const char *remote_midi_device; /* ID of MIDI device */
  const char *map_filename; /* name of glade file with mapping definitions */
};

#endif /* _CONTROLLER_H_ */

/************************** End of file contoller.h *************************/
