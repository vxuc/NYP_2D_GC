/**
 CSoundController
 By: Toh Da Jun
 Date: Mar 2020
 */
#pragma once

// Include SingletonTemplate
#include <DesignPatterns\SingletonTemplate.h>

// Include GLEW
#include <includes/irrKlang.h>
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

// Include string
#include <string>
// Include map storage
#include <map>
using namespace std;

// Include SoundInfo class; it stores the sound and other information
#include "SoundInfo.h"

class CSoundController : public CSingletonTemplate<CSoundController>
{
	friend CSingletonTemplate<CSoundController>;
public:
	// Initialise this class instance
	bool Init(void);

	// Load a sound
	bool LoadSound(	string filename, 
					const string name,
					const bool bPreload = true,
					const bool bIsLooped = false,
					CSoundInfo::SOUNDTYPE eSoundType = CSoundInfo::SOUNDTYPE::_2D,
					vec3df vec3dfSoundPos = vec3df(0.0f, 0.0f, 0.0f));

	// Play a sound by its ID
	void PlaySoundByID(const int ID);

	// Play a sound by its name
	void PlaySoundByName(const string name);

	// Stop all active sounds
	void StopAllSound();

	// Increase Master volume
	bool MasterVolumeIncrease(void);
	// Decrease Master volume
	bool MasterVolumeDecrease(void);

	// Increase volume of a ISoundSource
	bool VolumeIncrease(const string ID);
	// Decrease volume of a ISoundSource
	bool VolumeDecrease(const string ID);

	// For 3D sounds only
	// Set Listener position
	void SetListenerPosition(const float x, const float y, const float z);
	// Set Listener direction
	void SetListenerDirection(const float x, const float y, const float z);

protected:
	// Constructor
	CSoundController(void);

	// Destructor
	virtual ~CSoundController(void);

	// Get an sound from this map
	CSoundInfo* GetSound(const string ID);
	// Remove an sound from this map
	bool RemoveSound(const string ID);
	// Get the number of sounds in this map
	int GetNumOfSounds(void) const;

	// The handler to the irrklang Sound Engine
	ISoundEngine* cSoundEngine;

	// The map of all the entity created
	std::map<int, CSoundInfo*> soundMap;

	// The map of all sounds by name
	std::map<string, CSoundInfo*> soundMapByName;

	// For 3D sound only: Listener position
	vec3df vec3dfListenerPos;
	// For 3D sound only: Listender view direction
	vec3df vec3dfListenerDir;
};

