# Small fix - Skybox cloud clipping

Hello DEVs 🤗
I understand that most people use cloudless skyboxes in these times, but there is a graphic glitch (usually when the player teleports/dragging a game window) with "jumping" clouds.


▶️[Preview with glitch - slow cloud speed](https://i.gyazo.com/fbe7ed31ac52bc034a9ef691b38852f0.mp4)

This is very annoying with fast moving clouds:

▶️[Preview with glitch - fast cloud speed](https://i.gyazo.com/0e5144c11a5694ef182a7691ee4dc9fe.mp4)

and warping:

▶️[Preview with glitch - warping](https://i.gyazo.com/9518295e4f5ee7a2dca1d77d2117264d.mp4)

# Fix:

Client source:
```
\EterLib\SkyBox.cpp
```
void CSkyBox::RenderCloud()
replace whole:

	DWORD dwCurTime = CTimer::Instance().GetCurrentMillisecond();
	
	m_fCloudPositionU += m_fCloudScrollSpeedU * (float)( dwCurTime - m_dwlastTime ) * 0.001f;
	if (m_fCloudPositionU >= 1.0f)
		m_fCloudPositionU = 0.0f;
	
	m_fCloudPositionV += m_fCloudScrollSpeedV * (float)( dwCurTime - m_dwlastTime ) * 0.001f;
	if (m_fCloudPositionV >= 1.0f)
		m_fCloudPositionV = 0.0f;
	
	m_dwlastTime = dwCurTime;
with:

	if (m_fCloudPositionU >= 1.0f)
		m_fCloudPositionU = 0.0f;
	
	
	if (m_fCloudPositionV >= 1.0f)
		m_fCloudPositionV = 0.0f;
	m_fCloudPositionU += m_fCloudScrollSpeedU  * 0.030f;
	m_fCloudPositionV += m_fCloudScrollSpeedV *  0.030f;
like that:

![code](https://i.postimg.cc/nhBfcBp3/code.png)

> * 0.030f is optimal
I have no idea why they decided to use ms timer for scrolling clouds in the rendering function that already has own clock and frameskip settings (now it just scales with game fps counter).

With fix (when dragging client window)

▶️[Preview without glitch - slow cloud speed](https://i.gyazo.com/57e1f81fb852ed0a239b9dcd7fa86b63.mp4)

▶️[Preview without glitch - fast cloud speed](https://i.gyazo.com/702fe692670f2b3be2d7f249f90a9c72.mp4)

Warping:

▶️[Preview without glitch - warp](https://i.gyazo.com/51b8608731f8710380dbbacfe5b51a34.mp4)

Have a nice day ❤️
