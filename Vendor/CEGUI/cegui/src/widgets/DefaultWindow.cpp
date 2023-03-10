/***********************************************************************
	created:	28/8/2004
	author:		Paul D Turner
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2012 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#include "CEGUI/widgets/DefaultWindow.h"

namespace CEGUI
{
const String DefaultWindow::WidgetTypeName("DefaultWindow");

//----------------------------------------------------------------------------//
DefaultWindow::DefaultWindow(const String& type, const String& name) :
    Window(type, name)
{
    setSize(USize(cegui_reldim(1.0f), cegui_reldim(1.0f)));
}

//----------------------------------------------------------------------------//
void DefaultWindow::drawSelf(const RenderingContext& ctx, std::uint32_t drawModeMask)
{
    // There is no own graphics, so draw only if a renderer is attached
    if (d_windowRenderer)
        Window::drawSelf(ctx, drawModeMask);
    else
        d_needsRedraw = false;
}

}
