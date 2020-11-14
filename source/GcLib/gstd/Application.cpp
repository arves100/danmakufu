#include "Application.hpp"
#include "Logger.hpp"

using namespace gstd;

/**********************************************************
//Application
**********************************************************/
Application* Application::thisBase_ = NULL;
Application::Application()
{
	::InitCommonControls();
}
Application::~Application()
{
	SDL_Quit();

	thisBase_ = NULL;
}
bool Application::Initialize()
{
	if (thisBase_ != NULL)
		return false;
	thisBase_ = this;
	bAppRun_ = true;
	bAppActive_ = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return false;

	return true;
}
bool Application::Run()
{
	if (bAppRun_ == false) {
		return false;
	}

	try {
		bool res = _Initialize();
		if (res == false)
			throw gstd::wexception(L"初期化中に例外が発生しました。");
	} catch (std::exception& e) {
		std::wstring log = StringUtility::ConvertMultiToWide(e.what());
		Logger::WriteTop(log);
		Logger::WriteTop(L"初期化中に例外が発生しました。強制終了します。");
		bAppRun_ = false;
	} catch (gstd::wexception& e) {
		std::wstring log = e.what();
		Logger::WriteTop(log);
		Logger::WriteTop(L"初期化中に例外が発生しました。強制終了します。");
		bAppRun_ = false;
	} catch (...) {
		Logger::WriteTop(L"初期化中に例外が発生しました。強制終了します。");
		bAppRun_ = false;
	}

	SDL_Event evt;
	while (true) {
		if (bAppRun_ == false)
			break;
		if (SDL_PollEvent(&evt)) {
			WindowEvent(&evt);
		} else {
			if (bAppActive_ == false) {
				Sleep(10);
				continue;
			}
			try {
				if (_Loop() == false)
					break;
			} catch (std::exception& e) {
				std::wstring log = StringUtility::ConvertMultiToWide(e.what());
				Logger::WriteTop(log);
				Logger::WriteTop(L"実行中に例外が発生しました。終了します。");
				break;
			} catch (gstd::wexception& e) {
				std::wstring log = e.what();
				Logger::WriteTop(log);
				Logger::WriteTop(L"実行中に例外が発生しました。終了します。");
				break;
			}
			// catch(...)
			// {
			// 	Logger::WriteTop(L"実行中に例外が発生しました。終了します。");
			// 	break;
			// }
		}
	}

	bAppRun_ = false;

	try {
		bool res = _Finalize();
		if (res == false)
			throw gstd::wexception(L"終了中に例外が発生しました。");
	} catch (std::exception& e) {
		std::wstring log = StringUtility::ConvertMultiToWide(e.what());
		Logger::WriteTop(log);
		Logger::WriteTop(L"正常に終了できませんでした。");
	} catch (gstd::wexception& e) {
		std::wstring log = e.what();
		Logger::WriteTop(log);
		Logger::WriteTop(L"正常に終了できませんでした。");
		bAppRun_ = false;
	} catch (...) {
		Logger::WriteTop(L"正常に終了できませんでした。");
	}
	return true;
}
