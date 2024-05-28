#pragma once

#include "Application.h"

#ifdef PE_PLATFORM_MACOS

extern Pecan::Application* Pecan::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Pecan {

    int Main(int argc, char** argv)
    {
        while (g_ApplicationRunning)
        {
            Pecan::Application* app = Pecan::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }

        return 0;
    }

}

// On macOS, we use a standard main function for all builds
int main(int argc, char** argv)
{
    return Pecan::Main(argc, argv);
}

#endif // PE_PLATFORM_MACOS

#ifdef PE_PLATFORM_WINDOWS

extern Pecan::Application* Pecan::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Pecan {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Pecan::Application* app = Pecan::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#ifdef PE_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Pecan::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Pecan::Main(argc, argv);
}

#endif // PE_DIST

#endif // PE_PLATFORM_WINDOWS
