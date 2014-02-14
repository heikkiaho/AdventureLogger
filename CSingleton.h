/*
 * http://moodle2.karelia.fi/pluginfile.php/134826/mod_resource/content/3/week7/DesignPatterns_main.html
 * @Anssi Gröhn
 */

#include <cstddef>

template <class T>
class CSingleton
{
private:
/// Static pointer to only instance.
static T *m_pSingleton;
////////////////////
/// Copy constructor.
CSingleton( const CSingleton &ref){}
protected:
////////////////////
/// Default constructor.
CSingleton() {}
////////////////////
/// Destructor.
virtual ~CSingleton() {}
public:
////////////////////
/// Returns a pointer to this singleton.
inline static T *GetInstance()
{
if ( m_pSingleton == NULL )
{
m_pSingleton = new T();
}
return m_pSingleton;
}
/// Destroys this singleton.
inline static void DestroyInstance()
{
if ( m_pSingleton != NULL )
{
delete m_pSingleton;
m_pSingleton = NULL;
}
}
/// Checks is this object instantiated
static bool Exists()
{
return (m_pSingleton != NULL);
}
};
/////////////////////////////////////////////////////////////////
/// Initialize the static member in the derived classes.
template<class T> T *CSingleton<T>::m_pSingleton = NULL;
