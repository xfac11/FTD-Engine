#pragma once
#include<iostream>
namespace FTD
{
	struct Vector2
	{
		float x;
		float y;

		const float& dot(const Vector2& vec)const
		{
			return (x * vec.x + y * vec.y);
		};
		static const float& dot(const Vector2& vec, const Vector2& vec2) noexcept
		{
			return (vec2.x * vec.x + vec2.y * vec.y);
		};
		const Vector2& add(const Vector2& vec)const
		{
			return Vector2{ vec.x + x,vec.y + y};
		};
		static const Vector2& add(const Vector2& vec, const Vector2& vec2)
		{
			return Vector2{ vec.x + vec2.x,vec.y + vec2.y };
		};
		const Vector2& operator+(const Vector2& vec)const
		{
			return Vector2{ vec.x + x,vec.y + y };
		};
		const Vector2& operator-(const Vector2& vec)const
		{
			return Vector2{ vec.x - x,vec.y - y };
		};
		const Vector2& operator*(const float& scale)const
		{
			return Vector2{ scale * x, scale * y };
		};
		const Vector2& operator/(const float& scale)const
		{
			return Vector2{ x / scale, y / scale };
		};
		const Vector2& operator+(const float& vec)const
		{
			return Vector2{ vec + x,vec + y};
		};
		const float& cross(const Vector2& vec)const
		{
			return x * vec.y - y * vec.x;
		};
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vec)
		{
			os << "(" << vec.x << ", " << vec.y << ")";
			return os;
		};
		const float& length()const
		{
			return sqrt(x * x + y * y);
		};
		static const float& length(const Vector2& vec) noexcept
		{
			return (vec.x * vec.x + vec.y * vec.y);
		};
	};

	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		};
		Vector3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		};
		Vector3(const Vector3& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}
		void operator=(const Vector3& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}
		const float& dot(const Vector3& vec)const
		{
			return (x * vec.x + y * vec.y + z * vec.z);
		};
		static const float& dot(const Vector3& vec, const Vector3& vec2) noexcept
		{
			return (vec2.x * vec.x + vec2.y * vec.y + vec2.z * vec.z);
		};
		const Vector3& add(const Vector3& vec)const
		{
			return Vector3{ vec.x + x,vec.y + y,vec.z + z };
		};
		static const Vector3& add(const Vector3& vec, const Vector3& vec2)
		{
			return Vector3{ vec.x + vec2.x,vec.y + vec2.y,vec.z + vec2.z };
		};
		const Vector3& operator+(const Vector3& vec)const
		{
			return Vector3{ vec.x + x,vec.y + y,vec.z + z };
		};
		const Vector3& operator-(const Vector3& vec)const
		{
			return Vector3{ x - vec.x,y - vec.y ,z - vec.z };
		};
		
		const Vector3& operator/(const float& scale)const
		{
			Vector3 result = { x / scale, y / scale, z / scale };
			return result;
		};
		const Vector3& operator+(const float& vec)const
		{
			return Vector3{ vec + x,vec + y,vec + z };
		};
		const Vector3& cross(const Vector3& vec)const
		{
			return Vector3{ y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x };
		};
		const void normalize()
		{
			Vector3 copy = *this;
			float le = this->length();
			copy = copy / le;
			*this = copy;
		};
		static const Vector3& reflect(const Vector3& vec, const Vector3& normal)
		{
			Vector3 result;

			
			result = vec - (normal *(2 * (vec.dot(normal))));

			return result;
		};
		friend std::ostream& operator<<(std::ostream& os,const Vector3& vec)
		{
			os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
			return os;
		};
		const float& length()const
		{
			return sqrt(x * x + y * y + z * z);
		};
		static const float& length(const Vector3& vec) noexcept
		{
			return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		};
	};


	Vector3 operator*(const Vector3& vec,const float& scale)
	{
		return Vector3( scale * vec.x, scale * vec.y, scale * vec.z );
	};
	const Vector3& operator*(const float& scale, const Vector3& vec)
	{
		return vec * scale;
	};


	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		};
		Vector4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		};
		Vector4(const Vector3& vec, const float& oW)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = oW;
		}
		const float& dot(const Vector4& vec)const
		{
			return (x * vec.x + y * vec.y + z * vec.z + w* vec.w);
		};
		static const float& dot(const Vector4& vec, const Vector4& vec2) noexcept
		{
			return (vec2.x * vec.x + vec2.y * vec.y + vec2.z * vec.z + vec2.w * vec.w);
		};
		const Vector4& add(const Vector4& vec)const
		{
			return Vector4{ vec.x + x,vec.y + y,vec.z + z ,vec.w + w};
		};
		static const Vector4& add(const Vector4& vec, const Vector4& vec2)
		{
			return Vector4{ vec.x + vec2.x,vec.y + vec2.y,vec.z + vec2.z ,vec.w + vec2.w };
		};
		const Vector4& operator+(const Vector4& vec)const
		{
			return Vector4{ vec.x + x,vec.y + y,vec.z + z, vec.w + w };
		};
		const Vector4& operator-(const Vector4& vec)const
		{
			return Vector4{ vec.x - x,vec.y - y,vec.z - z, vec.w - w };
		};
		const Vector4& operator*(const float& scale)const
		{
			return Vector4{ scale * x, scale * y, scale * z, scale * w };
		};
		const Vector4& operator/(const float& scale)const
		{
			return Vector4{ x / scale, y / scale, z / scale, w / scale };
		};
		const Vector4& operator+(const float& vec)const
		{
			return Vector4{ vec + x,vec + y,vec + z, vec + w };
		};
		const Vector4& cross(const Vector4& vec)const
		{
			return Vector4{ y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x, w};
		};
		friend std::ostream& operator<<(std::ostream& os, const Vector4& vec)
		{
			os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
			return os;
		};
		const float& length()const
		{
			return sqrt(x * x + y * y + z * z);
		};
		static const float& length(const Vector4& vec) noexcept
		{
			return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		};
	};
}