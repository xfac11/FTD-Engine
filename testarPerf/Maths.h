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
		};
		void operator=(const Vector3& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
		};
		Vector3(const Vector2& vec, const float& oZ)
		{
			x = vec.x;
			y = vec.y;
			z = oZ;
		}
		const float dot(const Vector3& vec)const
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
		const Vector3 operator-(const Vector3& vec)const
		{
			return Vector3{ x - vec.x,y - vec.y ,z - vec.z };
		};
		
		const Vector3 operator/(const float& scale)const
		{
			Vector3 result = { x / scale, y / scale, z / scale };
			return result;
		};
		const Vector3& operator+(const float& vec)const
		{
			return Vector3{ vec + x,vec + y,vec + z };
		};
		const Vector3 cross(const Vector3& vec)const
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
		const Vector3 operator*(const float& scale)
		{
			return Vector3(scale * x, scale * y, scale * z);
		};
		static const Vector3 reflect(const Vector3& vec, const Vector3& normal)
		{
			Vector3 result;
			Vector3 nor((2 * (vec.dot(normal))) * normal.x, (2 * (vec.dot(normal))) * normal.y, (2 * (vec.dot(normal))) * normal.z);
			result = vec - nor;

			return result;
		};
		friend std::ostream& operator<<(std::ostream& os,const Vector3& vec)
		{
			os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
			return os;
		};
		const float length()const
		{
			return sqrt(x * x + y * y + z * z);
		};
		static const float& length(const Vector3& vec) noexcept
		{
			return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		};
	};


	
	const Vector3 operator*(const float& scale, const Vector3& vec)
	{
		Vector3 temp = vec;
		Vector3 result = temp * scale;
		return result;
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
		Vector4(const Vector4& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}
		void operator=(const Vector4& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}
		const float& dot(const Vector4& vec)const
		{
			float result;
			result = x * vec.x + y * vec.y + z * vec.z + w * vec.w;
			return result;
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

	struct Matrix
	{
		float mx[4][4];

		Matrix()
		{
			mx[0][0] = 0.0f;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					mx[i][j] = 0.0f;
				}
			}
		};
		// First number m11 means: m[1]1 is the row and m1[1] is the column
		Matrix(float m11, float m12, float m13, float m14,
			   float m21, float m22, float m23, float m24,
			   float m31, float m32, float m33, float m34,
			   float m41, float m42, float m43, float m44)
		{
			mx[0][0] = m11; mx[0][1] = m12; mx[0][2] = m13; mx[0][3] = m14;
			mx[1][0] = m21; mx[1][1] = m22; mx[1][2] = m23; mx[1][3] = m24;  
			mx[2][0] = m31;	mx[2][1] = m32;	mx[2][2] = m33; mx[2][3] = m34;
			mx[3][0] = m41;	mx[3][1] = m42;	mx[3][2] = m43; mx[3][3] = m44;
						
		};

		Matrix(Vector4 row1, Vector4 row2, Vector4 row3, Vector4 row4)
		{
			mx[0][0] = row1.x; mx[0][1] = row1.y; mx[0][2] = row1.y; mx[0][3] = row1.w;
			mx[1][0] = row2.x; mx[1][1] = row2.y; mx[1][2] = row2.y; mx[1][3] = row2.w;
			mx[2][0] = row3.x; mx[2][1] = row3.y; mx[2][2] = row3.y; mx[2][3] = row3.w;
			mx[3][0] = row4.x; mx[3][1] = row4.y; mx[3][2] = row4.y; mx[3][3] = row4.w;
		}

		Matrix(const Matrix& aMx)
		{
			mx[0][0] = aMx.mx[0][0]; mx[0][1] = aMx.mx[0][1]; mx[0][2] = aMx.mx[0][2]; mx[0][3] = aMx.mx[0][3];
			mx[1][0] = aMx.mx[1][0]; mx[1][1] = aMx.mx[1][1]; mx[1][2] = aMx.mx[1][2]; mx[1][3] = aMx.mx[1][3];
			mx[2][0] = aMx.mx[2][0]; mx[2][1] = aMx.mx[2][1]; mx[2][2] = aMx.mx[2][2]; mx[2][3] = aMx.mx[2][3];
			mx[3][0] = aMx.mx[3][0]; mx[3][1] = aMx.mx[3][1]; mx[3][2] = aMx.mx[3][2]; mx[3][3] = aMx.mx[3][3];
		}

		void operator=(const Matrix& aMx)
		{
			mx[0][0] = aMx.mx[0][0]; mx[0][1] = aMx.mx[0][1]; mx[0][2] = aMx.mx[0][2]; mx[0][3] = aMx.mx[0][3];
			mx[1][0] = aMx.mx[1][0]; mx[1][1] = aMx.mx[1][1]; mx[1][2] = aMx.mx[1][2]; mx[1][3] = aMx.mx[1][3];
			mx[2][0] = aMx.mx[2][0]; mx[2][1] = aMx.mx[2][1]; mx[2][2] = aMx.mx[2][2]; mx[2][3] = aMx.mx[2][3];
			mx[3][0] = aMx.mx[3][0]; mx[3][1] = aMx.mx[3][1]; mx[3][2] = aMx.mx[3][2]; mx[3][3] = aMx.mx[3][3];
		}
		const Vector4& getRow(int row)const
		{
			Vector4 result(mx[row][0],mx[row][1], mx[row][2], mx[row][3]);

			return result;
		};
		const Vector4& getCol(int col)const
		{
			Vector4 result(mx[0][col], mx[1][col], mx[2][col], mx[3][col]);

			return result;
		};
		const Matrix& operator*(const float& scale)const
		{
			Matrix result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result.mx[i][j] = scale*mx[i][j];
				}
			}
			return result;
		};

		const Matrix& operator*(const Matrix& rightMx)const
		{
			Matrix result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result.mx[i][j] = mx[i][0] * rightMx.mx[0][j] + mx[i][1] * rightMx.mx[1][j] + mx[i][2] * rightMx.mx[2][j] + mx[i][3] * rightMx.mx[3][j];
				}
			}
			return result;
		};

		#ifdef _DEBUG
		friend std::ostream& operator<<(std::ostream& os, const Matrix& aMx)
		{
			
			for (int i = 0; i < 4; i++)
			{
				os << "(";
				for (int j = 0; j < 4; j++)
				{
					os << " "<< aMx.mx[i][j] << " ";
				}
				os << ")" << std::endl;
			}
			//<< vec.x << ", " << vec.y << ", " << vec.z << ")";
			
			return os;
		};
		#endif	
	};
}