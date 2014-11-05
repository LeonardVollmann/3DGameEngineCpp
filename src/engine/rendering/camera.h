#ifndef CAMERA_H
#define CAMERA_H

#include "../core/math.h"
#include "../core/input.h"

class Camera
{
public:
	Camera(const Vector3f &pos = Vector3f(0.0f, 0.0f, 0.0f), const Vector3f &forward = Vector3f(0.0f, 0.0f, 1.0f), const Vector3f &up = Vector3f(0.0f, 1.0f, 0.0f), float fov = 70.0f, float aspect = 1.0f, float zNear = 0.1f, float zFar = 1000.0f);

	void processInput(Input &input);

	const Matrix4f getViewProjection() const;

	void move(const Vector3f &direction, float amount);
	void rotate(const Vector3f &angle, float axis);

	inline const Matrix4f &getProjection() const { return m_projection; }
	inline const Vector3f &getPos() const { return m_pos; }
	inline const Vector3f &getForward() const { return m_forward; }
	inline const Vector3f &getUp() const { return m_up; }
	inline const Vector3f getBackward() const { return m_forward * -1.0f; }
	inline const Vector3f getDown() const { return m_up * -1.0f; }
	inline const Vector3f getRight() const { return m_forward.cross(m_up); }
	inline const Vector3f getLeft() const { return m_up.cross(m_forward); }

	inline void setProjection(float fov, float aspect, float zNear, float zFar) { m_projection = Matrix4f().initProjection(fov, aspect, zNear, zFar); }
protected:
private:
	constexpr static float CAM_SPEED = 0.2f;
	constexpr static float MOUSE_SENSITIVITY = 0.2f;

	Vector3f m_pos;
	Vector3f m_forward;
	Vector3f m_up;

	bool m_mouseLocked;
	Vector2f m_windowCenter;

	Matrix4f m_projection;
};

#endif
