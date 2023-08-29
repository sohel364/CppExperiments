#include "Child3.h"


/// <summary>Constructor, destructor, and move operators must be out-of-line if std::unique_ptr<> members exist, see http://herbsutter.com/gotw/_100/</summary>
Child3::Child3() = default;
Child3::Child3(Child3&&) noexcept = default;
Child3& Child3::operator=(Child3&&) noexcept = default;
Child3::~Child3() = default;