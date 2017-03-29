/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Geomtric Primitives
box, circle, sphere, cone

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_21_GEOMTRIC_PRIMITIVES_H_
#define CP5_EX15_21_GEOMTRIC_PRIMITIVES_H_

inline namespace EX21 {

	static const float PI = 3.14159f;

	class Shape {
	public:
		virtual const char* shape_name() = 0;
		virtual void resize_by_percentage(float pct) = 0;
		virtual ~Shape() {}
	};

	class Shape_2D : public Shape {
	public:
		Shape_2D() = default;
		Shape_2D(float x, float y) : x_(x), y_(y) {}

		virtual float area() const = 0;
		virtual float diameter() const = 0;
		virtual float circumference() const = 0;

		virtual ~Shape_2D() override {}

	protected:
		float x_ = 0.f;
		float y_ = 0.f;
	};

	class Shape_3D : public Shape {
	public:
		Shape_3D() = default;
		Shape_3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}

		virtual float volume() const = 0;

		virtual ~Shape_3D() override {}

	protected:
		float x_ = 0.f;
		float y_ = 0.f;
		float z_ = 0.f;
	};

	class Box : public Shape_3D {
	public:
		Box() = default;
		explicit Box(float width) : half_len_x_(width * 0.5f), half_len_y_(width * 0.5f), half_len_z_(width * 0.5f) {}
		Box(float center_x, float center_y, float center_z, float len_x, float len_y, float len_z) : Shape_3D(center_x, center_y, center_z),
		half_len_x_(len_x * 0.5f), half_len_y_(len_y * 0.5f), half_len_z_(len_z * 0.5f) {}

		inline virtual const char* shape_name() override { return "Box"; }
		inline virtual void resize_by_percentage(float pct) override { half_len_x_ *= pct; half_len_y_ *= pct; half_len_z_ *= pct; }

		inline float volume() const override { return half_len_x_ * half_len_y_ * half_len_z_ * 8; }

		virtual ~Box() override {}

	protected:
		float half_len_x_ = 0.5f;
		float half_len_y_ = 0.5f;
		float half_len_z_ = 0.5f;
	};

	class Circle : public Shape_2D {
	public:
		Circle() = default;
		explicit Circle(float radius) : radius_(radius) {}
		Circle(float center_x, float center_y, float radius) : Shape_2D(center_x, center_y), radius_(radius) {}

		inline virtual float area() const override { return PI * radius_ * radius_; }
		inline virtual float diameter() const override { return 2 * radius_; }
		inline virtual float circumference() const override { return 2 * PI * radius_; }

		inline virtual const char* shape_name() override { return "Circle"; }
		inline virtual void resize_by_percentage(float pct) override { radius_ *= pct; }

		virtual ~Circle() override {}

	protected:
		float radius_ = 1.f;
	};

	class Sphere : public Shape_3D {
	public:
		Sphere() = default;
		explicit Sphere(float radius) : radius_(radius) {}
		Sphere(float center_x, float center_y, float center_z, float radius) : Shape_3D(center_x, center_y, center_z), radius_(radius) {}

		inline virtual const char* shape_name() override { return "Sphere"; }
		inline virtual void resize_by_percentage(float pct) override { radius_ *= pct; }

		inline float volume() const override { return 4 * PI * radius_ * radius_ * radius_ / 3; }

		virtual ~Sphere() override {}

	protected:
		float radius_ = 1.f;
	};

	class Cone : public Shape_3D {
	public:
		Cone() = default;
		Cone(float radius, float height) : radius_(radius), height_(height) {}
		Cone(float center_x, float center_y, float center_z, float radius, float height) : Shape_3D(center_x, center_y, center_z), radius_(radius), height_(height) {}

		inline virtual const char* shape_name() override { return "Cone"; }
		inline virtual void resize_by_percentage(float pct) override { radius_ *= pct; height_ *= pct; }

		inline float volume() const override { return PI * radius_ * radius_ * height_ / 3; }

		virtual ~Cone() override {}

	protected:
		float radius_ = 1.f;
		float height_ = 1.f;
	};
}

#endif // CP5_EX15_21_GEOMTRIC_PRIMITIVES_H_
