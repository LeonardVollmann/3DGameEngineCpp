#include "camera.h"

Camera::Camera(const Vector3f &pos, const Vector3f &forward, const Vector3f &up, float fov, float aspect, float zNear, float zFar) :
	m_pos(pos),
	m_forward(forward),
	m_up(up)
{
	setProjection(fov, aspect, zNear, zFar);
}

void Camera::processInput(Input &input)
{
	if (input.getKey(Input::KEY_W)) {
		move(m_forward, CAM_SPEED);
	}
	if (input.getKey(Input::KEY_S)) {
		move(getBackward(), CAM_SPEED);
	}
	if (input.getKey(Input::KEY_A)) {
		move(getLeft(), CAM_SPEED);
	}
	if (input.getKey(Input::KEY_D)) {
		move(getRight(), CAM_SPEED);
	}
	
	if (m_mouseLocked) {
		if (input.getKey(Input::KEY_ESCAPE)) {
			m_mouseLocked = false;
			input.setMouseVisible(true);
		}	

		Vector2f mouseDistance = input.getMousePosition() - m_windowCenter;
		
		bool rotateX = mouseDistance.getY() != 0;
		bool rotateY = mouseDistance.getX() != 0;

		if (rotateX) {
			rotate(Vector3f(1.0f, 0.0f, 0.0f), mouseDistance.getX() * MOUSE_SENSITIVITY);
		}
		if (rotateY) {
			rotate(Vector3f(0.0f, 1.0f, 0.0f), mouseDistance.getY() * MOUSE_SENSITIVITY);
		}
	}

	if (input.getMouseButton(Input::MOUSE_LEFT_BUTTON)) {
		m_mouseLocked = true;
		input.setMouseVisible(false);
		input.warpMouse(m_windowCenter);
	}
}

void Camera::move(const Vector3f &direction, float amount)
{
	m_pos += direction * amount;
}	

void Camera::rotate(const Vector3f &axis, float angle)
{
	Quaternion rotation = Quaternion().initFromAxisAngle(axis, angle);

	m_forward = m_forward.rotate(rotation);
	m_up = m_up.rotate(rotation);
}

const Matrix4f Camera::getViewProjection() const
{
	Matrix4f view = Matrix4f().initView(m_pos, m_forward, m_up);
	return m_projection * view;
}
