// DSAudioFactory.cpp
// KlayGE DSound音频引擎抽象工厂类 实现文件
// Ver 2.0.0
// 版权所有(C) 龚敏敏, 2003
// Homepage: http://klayge.sourceforge.net
//
// 2.0.0
// 初次建立 (2003.10.4)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#include <KlayGE/KlayGE.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/AudioFactory.hpp>

#include <KlayGE/DSound/DSAudio.hpp>
#include <KlayGE/DSound/DSAudioFactory.hpp>

extern "C"
{
	void MakeAudioFactory(KlayGE::AudioFactoryPtr& ptr, boost::program_options::variables_map const & /*vm*/)
	{
		ptr = KlayGE::MakeSharedPtr<KlayGE::ConcreteAudioFactory<KlayGE::DSAudioEngine,
			KlayGE::DSSoundBuffer, KlayGE::DSMusicBuffer> >(L"DirectSound Audio Factory");
	}	

	bool Match(char const * name, char const * compiler)
	{
		std::string cur_compiler_str = KLAYGE_COMPILER_TOOLSET;
#ifdef KLAYGE_DEBUG
		cur_compiler_str += "_d";
#endif

		if ((std::string("DSound") == name) && (cur_compiler_str == compiler))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
