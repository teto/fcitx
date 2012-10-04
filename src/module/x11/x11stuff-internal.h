/***************************************************************************
 *   Copyright (C) 2010~2012 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef X11STUFF_INTERNAL_H
#define X11STUFF_INTERNAL_H

#include "config.h"
#include "fcitx/fcitx.h"
#include "x11stuff.h"
#include "x11handlertable.h"

typedef struct {
    Display *dpy;
    UT_array handlers;
    UT_array comphandlers;
    FcitxInstance* owner;
    Window compManager;
    Window rootWindow;
    Window eventWindow;
    Atom compManagerAtom;
    int iScreen;
    Atom typeMenuAtom;
    Atom windowTypeAtom;
    Atom typeDialogAtom;
    Atom typeDockAtom;
    Atom pidAtom;
    boolean bUseXinerama;
    FcitxRect* rects;
    int screenCount;
    int defaultScreen;
    FcitxAddon* xim;
    double dpif;
    int dpi;
    boolean firstRun;
#ifdef HAVE_XFIXES
    boolean hasXfixes;
    int xfixesEventBase;
    FcitxHandlerTable *selectionNotify;
#endif
    boolean isComposite;
    FcitxHandlerTable *convertSelection;
} FcitxX11;

typedef void (*FcitxCallBack)();

typedef void (*X11ConvertSelectionInternalCallback)(
    FcitxX11 *x11priv, void *owner, Atom selection, Atom target, int format,
    size_t nitems, const void *buff, void *data, FcitxCallBack func);
typedef void (*X11SelectionNotifyInternalCallback)(
    FcitxX11 *x11priv, void *owner, Atom selection, int subtype,
    void *data, FcitxCallBack func);

#endif
// kate: indent-mode cstyle; space-indent on; indent-width 0;
