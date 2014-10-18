//
//  window.h
//  GameEngine3D
//
//  Created by Leonard Vollmann on 18/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#ifndef __GameEngine3D__window__
#define __GameEngine3D__window__

#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(const std::string &title, unsigned int width, unsigned int height);
    virtual ~Window();
    
    void update();
    void clear(float r, float g, float b, float a);
    
    inline bool isClosed() const               { return m_closed; }
    inline const std::string &getTitle() const { return m_title; }
    inline unsigned int getWidth() const       { return m_width; }
    inline unsigned int getHeight() const      { return m_height; }
    inline float getAspectRatio() const        { return (float)m_width / (float)m_height; }
protected:
private:
    std::string m_title;
    unsigned int m_width;
    unsigned int m_height;
    
    SDL_Window *m_window;
    SDL_GLContext m_glContext;
    
    bool m_closed;
};

#endif /* defined(__GameEngine3D__window__) */