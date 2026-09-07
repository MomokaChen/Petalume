#pragma once

#ifdef PL_PLATFORM_WINDOWS

extern Petalume::Application* Petalume::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Petalume::CreateApplication();
	app->Run();
	delete app;
}

#endif