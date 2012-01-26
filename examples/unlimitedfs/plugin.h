#ifndef UNLIMIITEDFS_PLUGIN_H
#define UNLIMIITEDFS_PLUGIN_H

#include <string>
#include <sampgdk/amx.h>

enum PluginError {
	PLUGIN_ERROR_OK,
	PLUGIN_ERROR_LOAD,
	PLUGIN_ERROR_VERSION,
	PLUGIN_ERROR_API
};

class Plugin {
public:
	typedef unsigned int (PLUGIN_CALL *Supports_t)();
	typedef bool (PLUGIN_CALL *Load_t)(void **ppData);
	typedef void (PLUGIN_CALL *Unload_t)();
	typedef int (PLUGIN_CALL *AmxLoad_t)(AMX *amx);
	typedef int (PLUGIN_CALL *AmxUnload_t)(AMX *amx);
	typedef void (PLUGIN_CALL *ProcessTick_t)();

	Plugin();
	explicit Plugin(const std::string &filename);
	Plugin(const std::string &filename, void **ppData);
	~Plugin();

	PluginError Load(void **ppData);
	PluginError Load(const std::string &filename, void **ppData);
	void Unload();

	std::string GetError() const
		{ return error_; }

	void *GetSymbol(const std::string &name) const;

	bool IsLoaded() const
		{ return loaded_; }
	operator bool() const
		{ return IsLoaded(); }

	int AmxLoad(AMX *amx) const;
	int AmxUnload(AMX *amx) const;
	void ProcessTick() const;

private:
	// Disable copying
	Plugin(const Plugin &other);
	Plugin &operator=(const Plugin &other);

	std::string filename_;
	void *handle_;
	bool loaded_;

	// Error string
	std::string error_;

	AmxLoad_t AmxLoad_;
	AmxUnload_t AmxUnload_;
	ProcessTick_t ProcessTick_;
};

#endif // UNLIMIITEDFS_PLUGIN_H