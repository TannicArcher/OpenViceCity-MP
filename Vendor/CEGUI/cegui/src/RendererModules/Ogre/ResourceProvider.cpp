/************************************************************************
    created:    8/7/2004
    author:     James '_mental_' O'Sullivan

    purpose: Implements Ogre specific ResourceProvider
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2009 Paul D Turner & The CEGUI Development Team
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
#include "CEGUI/RendererModules/Ogre/ResourceProvider.h"
#include "CEGUI/Exceptions.h"
#include "CEGUI/RendererModules/Ogre/OgreMacros.h"
#include "CEGUI/DataContainer.h"

#include <OgreArchiveManager.h>
#include <OgreResourceGroupManager.h>

// Start of CEGUI namespace section
namespace CEGUI
{
//----------------------------------------------------------------------------//
OgreResourceProvider::OgreResourceProvider()
{
    // set deafult resource group for Ogre
    d_defaultResourceGroup =
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str();
}

//----------------------------------------------------------------------------//
void OgreResourceProvider::loadRawDataContainer(const String& filename,
                                                RawDataContainer& output,
                                                const String& resourceGroup)
{
    String orpGroup;
    if (resourceGroup.empty())
        orpGroup = d_defaultResourceGroup.empty() ?
            Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str() :
            d_defaultResourceGroup;
    else
        orpGroup = resourceGroup;

#if (CEGUI_STRING_CLASS != CEGUI_STRING_CLASS_UTF_32) 
    Ogre::DataStreamPtr input = Ogre::ResourceGroupManager::getSingleton().
        openResource(filename.c_str(), orpGroup.c_str());
#else
    Ogre::DataStreamPtr input = Ogre::ResourceGroupManager::getSingleton().
        openResource(String::convertUtf32ToUtf8(filename.getString()).c_str(), String::convertUtf32ToUtf8(orpGroup.getString()).c_str());
#endif

    if (OGRE_ISNULL(input))
        throw InvalidRequestException(
            "Unable to open resource file '" + filename +
            "' in resource group '" + orpGroup + "'.");

    Ogre::String buf = input->getAsString();
    const size_t memBuffSize = buf.length();

    unsigned char* mem = new unsigned char[memBuffSize];
    memcpy(mem, buf.c_str(), memBuffSize);

    output.setData(mem);
    output.setSize(memBuffSize);
}

//----------------------------------------------------------------------------//
void OgreResourceProvider::unloadRawDataContainer(RawDataContainer& data)
{
    if (data.getDataPtr())
    {
        delete[] data.getDataPtr();
        data.setData(0);
        data.setSize(0);
    }
}

//----------------------------------------------------------------------------//
size_t OgreResourceProvider::getResourceGroupFileNames(
    std::vector<String>& out_vec, const String& file_pattern,
    const String& resource_group)
{
    // get list of files in the group that match the pattern.
#if (CEGUI_STRING_CLASS != CEGUI_STRING_CLASS_UTF_32) 
    Ogre::StringVectorPtr vp =
        Ogre::ResourceGroupManager::getSingleton().findResourceNames(
            (resource_group.empty() ?
                d_defaultResourceGroup.c_str() :
                resource_group.c_str()),
            file_pattern.c_str());
#else
    Ogre::StringVectorPtr vp =
        Ogre::ResourceGroupManager::getSingleton().findResourceNames(
            (resource_group.empty() ?
                String::convertUtf32ToUtf8(d_defaultResourceGroup.getString()).c_str() :
                String::convertUtf32ToUtf8(resource_group.getString()).c_str()),
            String::convertUtf32ToUtf8(file_pattern.getString()).c_str());
#endif

    size_t entries = 0;
    Ogre::StringVector::iterator i = vp->begin();
    for (; i != vp->end(); ++i)
    {
        out_vec.push_back(i->c_str());
        ++entries;
    }

    return entries;
}

//----------------------------------------------------------------------------//

} // End of  CEGUI namespace section
