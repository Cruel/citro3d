#include <c3d/maths.h>

void Mtx_RotateX(C3D_Mtx* mtx, float angle, bool bRightSide)
{
	C3D_Mtx rm, om;

	float cosAngle = cosf(angle);
	float sinAngle = sinf(angle);

	Mtx_Zeros(&rm);
	rm.r[0].x = 1.0f;
	rm.r[1].y = cosAngle;
	rm.r[1].z = sinAngle;
	rm.r[2].y = -sinAngle;
	rm.r[2].z = cosAngle;
	rm.r[3].w = 1.0f;

	if (bRightSide) Mtx_Multiply(&om, mtx, &rm);
	else            Mtx_Multiply(&om, &rm, mtx);
	Mtx_Copy(mtx, &om);
}
