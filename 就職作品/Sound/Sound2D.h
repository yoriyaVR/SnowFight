#pragma once
#include"../ResourceManager.h"
#include<string>

struct SoundInitData {
	SoundID ID;
	bool LoopFlag;			//Loopさせるかtrue = Loop再生
	int Volume;				//再生音量0〜-10,000
	int  MaxPlayCnt;		//同時にならせる最大数(この数分配列を確保する)
	std::string FileName;
};

class Sound2D {
public:
	Sound2D();
	virtual ~Sound2D();
	void Initialize(const SoundInitData& _SoundInitData);

	void Play();
	void Stop();

	bool IsPlaying();
	int GetMaxPlayCnt(void);
protected:
	//---------------------------------------------------
	//変数
	//---------------------------------------------------
	SoundInitData soundData;
	LPDIRECTSOUNDBUFFER8 Buffer;
private:

};