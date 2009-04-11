// ShaderObject.hpp
// KlayGE shader对象类 头文件
// Ver 3.8.0
// 版权所有(C) 龚敏敏, 2006-2009
// Homepage: http://klayge.sourceforge.net
//
// 3.8.0
// 支持Gemoetry Shader (2009.2.5)
//
// 3.7.0
// 改为直接传入RenderEffect (2008.7.4)
//
// 3.5.0
// 初次建立 (2006.11.2)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _SHADEROBJECT_HPP
#define _SHADEROBJECT_HPP

#pragma KLAYGE_ONCE

#include <KlayGE/PreDeclare.hpp>

namespace KlayGE
{
	struct shader_desc
	{
		std::string profile;
		std::string func_name;

		friend bool operator==(shader_desc const & lhs, shader_desc const & rhs)
		{
			return (lhs.profile == rhs.profile) && (lhs.func_name == rhs.func_name);
		}
		friend bool operator!=(shader_desc const & lhs, shader_desc const & rhs)
		{
			return !(lhs == rhs);
		}
	};

	class KLAYGE_CORE_API ShaderObject
	{
	public:
		enum ShaderType
		{
			ST_VertexShader,
			ST_PixelShader,
			ST_GeometryShader,

			ST_NumShaderTypes
		};

	public:
		virtual ~ShaderObject()
		{
		}

		static ShaderObjectPtr NullObject();

		virtual void SetShader(RenderEffect& effect, boost::shared_ptr<std::vector<shader_desc> > const & shader_descs) = 0;
		virtual ShaderObjectPtr Clone(RenderEffect& effect) = 0;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		bool Validate() const
		{
			return is_validate_;
		}

	protected:
		bool is_validate_;
	};
}

#endif			// _SHADEROBJECT_HPP
