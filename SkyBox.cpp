// Search:
void CSkyBox::RenderCloud()

// replace whole:
DWORD dwCurTime = CTimer::Instance().GetCurrentMillisecond();

m_fCloudPositionU += m_fCloudScrollSpeedU * (float)( dwCurTime - m_dwlastTime ) * 0.001f;
if (m_fCloudPositionU >= 1.0f)
	m_fCloudPositionU = 0.0f;

m_fCloudPositionV += m_fCloudScrollSpeedV * (float)( dwCurTime - m_dwlastTime ) * 0.001f;
if (m_fCloudPositionV >= 1.0f)
	m_fCloudPositionV = 0.0f;

m_dwlastTime = dwCurTime;

// with:

if (m_fCloudPositionU >= 1.0f)
	m_fCloudPositionU = 0.0f;


if (m_fCloudPositionV >= 1.0f)
	m_fCloudPositionV = 0.0f;
m_fCloudPositionU += m_fCloudScrollSpeedU  * 0.030f;
m_fCloudPositionV += m_fCloudScrollSpeedV *  0.030f;