/***********************************************************************
    created:    Tue Feb 17 2009
    author:     Paul D Turner
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2011 Paul D Turner & The CEGUI Development Team
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
#ifndef _CEGUIOgreTexture_h_
#define _CEGUIOgreTexture_h_

#include "../../Texture.h"
#include "CEGUI/RendererModules/Ogre/Renderer.h"
#ifdef CEGUI_USE_OGRE_TEXTURE_GPU
#include <OgreTextureGpu.h>
#else
#include <OgreTexture.h>
#include <OgreSharedPtr.h>
#endif // CEGUI_USE_OGRE_TEXTURE_GPU

// Start of CEGUI namespace section
namespace CEGUI
{
//! Implementation of the CEGUI::Texture class for the Ogre engine.
class OGRE_GUIRENDERER_API OgreTexture : public Texture
{
public:
    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    //! Set the underlying Ogre texture.
    void setOgreTexture(Ogre::TextureGpu* texture, bool take_ownership = false);
    //! Return Ogre::TexturePtr for the underlying Ogre texture.
    Ogre::TextureGpu* getOgreTexture() const;
    #else
    //! Set the underlying Ogre texture.
    void setOgreTexture(Ogre::TexturePtr texture, bool take_ownership = false);
    //! Return Ogre::TexturePtr for the underlying Ogre texture.
    Ogre::TexturePtr getOgreTexture() const;
    #endif // CEGUI_USE_OGRE_TEXTURE_GPU

    //! return a Ogre::string containing a unique name.
    static Ogre::String getUniqueName();

    // implement CEGUI::Texture interface
    const String& getName() const;
    const Sizef& getSize() const;
    const Sizef& getOriginalDataSize() const;
    const glm::vec2& getTexelScaling() const;
    void loadFromFile(const String& filename, const String& resourceGroup);
    void loadFromMemory(const void* buffer, const Sizef& buffer_size,
                        PixelFormat pixel_format);
    void blitFromMemory(const void* sourceData, const Rectf& area);
    void blitToMemory(void* targetData);
    bool isPixelFormatSupported(const PixelFormat fmt) const;
    bool textureIsLinked() const;

    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    //! convert Ogre::PixelFormatGpu to equivalent CEGUI::Texture::PixelFormat
    static Texture::PixelFormat fromOgrePixelFormat(const Ogre::PixelFormatGpu fmt);
    //! convert CEGUI::Texture::PixelFormat to equivalent Ogre::PixelFormatGpu
    static Ogre::PixelFormatGpu toOgrePixelFormat(const Texture::PixelFormat fmt);
    #else
    //! convert Ogre::PixelFormat to equivalent CEGUI::Texture::PixelFormat
    static Texture::PixelFormat fromOgrePixelFormat(const Ogre::PixelFormat fmt);
    //! convert CEGUI::Texture::PixelFormat to equivalent Ogre::PixelFormat
    static Ogre::PixelFormat toOgrePixelFormat(const Texture::PixelFormat fmt);
    #endif // CEGUI_USE_OGRE_TEXTURE_GPU

protected:
    // we all need a little help from out friends ;)
    friend Texture& OgreRenderer::createTexture(const String&, bool);
    friend Texture& OgreRenderer::createTexture(const String&, const String&,
                                                const String&);
    friend Texture& OgreRenderer::createTexture(const String&, const Sizef&);
    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    friend Texture& OgreRenderer::createTexture(const String&, Ogre::TextureGpu*,
                                                bool);
    #else
    friend Texture& OgreRenderer::createTexture(const String&, Ogre::TexturePtr&,
                                                bool);
    #endif // CEGUI_USE_OGRE_TEXTURE_GPU
    friend void OgreRenderer::destroyTexture(Texture&);
    friend void OgreRenderer::destroyTexture(const String&);

    //! standard constructor
    OgreTexture(const String& name, bool notNullTexture = true);
    //! construct texture via an image file.
    OgreTexture(const String& name, const String& filename,
                const String& resourceGroup);
    //! construct texture with a specified initial size.
    OgreTexture(const String& name, const Sizef& sz);
    //! construct texture from existing Ogre texture.
    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    OgreTexture(const String& name, Ogre::TextureGpu* tex, bool take_ownership);
    #else
    OgreTexture(const String& name, Ogre::TexturePtr& tex, bool take_ownership);
    #endif // CEGUI_USE_OGRE_TEXTURE_GPU


    //! destructor.
    virtual ~OgreTexture();
    //! construct an empty texture
    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    void createOgreTexture(
        Ogre::PixelFormatGpu pixel_format = Ogre::PFG_RGBA8_UNORM,
        std::uint32_t width = 1, std::uint32_t height = 1,
        Ogre::GpuPageOutStrategy::GpuPageOutStrategy pageOutStrategy = Ogre::GpuPageOutStrategy::Discard
    );
    #else
    void createEmptyOgreTexture(PixelFormat pixel_format = Texture::PixelFormat::Rgba);
    #endif
    //! release the underlying Ogre texture.
    void freeOgreTexture();
    //! updates cached scale value used to map pixels to texture co-ords.
    void updateCachedScaleValues();

    //! Counter used to provide unique texture names.
    static std::uint32_t d_textureNumber;
    //!< The underlying Ogre texture.
    #ifdef CEGUI_USE_OGRE_TEXTURE_GPU
    Ogre::TextureGpu* d_texture;
    #else
    Ogre::TexturePtr d_texture;
    #endif // CEGUI_USE_OGRE_TEXTURE_GPU
    //! specifies whether d_texture was created externally (not owned by us).
    bool d_isLinked;
    //! Size of the texture.
    Sizef d_size;
    //! original pixel of size data loaded into texture
    Sizef d_dataSize;
    //! cached pixel to texel mapping scale values.
    glm::vec2 d_texelScaling;
    //! Name this texture was created with.
    const String d_name;
};

} // End of  CEGUI namespace section

#endif  // end of guard _CEGUIOgreTexture_h_
