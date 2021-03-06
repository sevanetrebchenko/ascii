
#include <framework/shader_library.h>

namespace Sandbox {

    void ShaderLibrary::AddShader(Shader *shader) {
        _shaders.emplace(shader->GetName(), shader);
        _recompileTargets.push_back(shader);
    }

    void ShaderLibrary::AddShader(const std::string &shaderName, const std::initializer_list<std::string> &shaderComponentPaths) {
        Shader* shader = new Shader(shaderName, shaderComponentPaths);

        _shaders.emplace(shaderName, shader);
        _recompileTargets.push_back(shader);
    }

    Shader *ShaderLibrary::GetShader(const std::string &shaderName) {
        auto shaderIter = _shaders.find(shaderName);

        // Found shader in library.
        if (shaderIter != _shaders.end()) {
            return shaderIter->second;
        }

        return nullptr;
    }

    void ShaderLibrary::RecompileAllModified() {
        for (IReloadable* target : _recompileTargets) {
            target->RecompileIfModified();
        }
    }

    void ShaderLibrary::RecompileAll() {
        for (const auto& shaderPair : _shaders) {
            shaderPair.second->Recompile();
        }
    }

    ShaderLibrary &ShaderLibrary::GetInstance() {
        static ShaderLibrary instance;
        return instance;
    }

    ShaderLibrary::ShaderLibrary() {

    }

    ShaderLibrary::~ShaderLibrary() {
        for (const auto& shaderPair : _shaders) {
            delete shaderPair.second;
        }
    }

}