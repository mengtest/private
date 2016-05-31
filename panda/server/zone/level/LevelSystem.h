// --------------------------------------------------------
/*Copyright KeyeLeo.All rights reserved.
*
*File		: LevelSystem.h
*Desc		:
*Version	: 1.0
*Program	: Vic
*Date		: 2016-4-25
*/
// --------------------------------------------------------
#ifndef _LevelSystem_h_
#define _LevelSystem_h_

class LevelSystem{
public:
	void		init(const char* cfg);
	Level*		findLevel(unsigned id);

	std::map<size_t,Level>	levels;
};
// --------------------------------------------------------
#endif // _LevelSystem_h_
