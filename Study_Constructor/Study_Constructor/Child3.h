class Child3
{
public:
	/// <summary>Default constructor. Creates an empty object.</summary>
	Child3();

	Child3(const Child3&) = default;
	Child3& operator=(const Child3&) = default;

	/// <summary>
	/// Constructs an object by moving the ownership of the Child3 implementation from
	/// the right hand side to this.
	/// </summary>
	/// <param name="rhs">[in,out] The right hand side.</param>
	Child3(Child3&& rhs) noexcept;

	/// <summary>
	/// Assigns the ownership of the Child3 implementation from the right hand side to
	/// this.
	/// </summary>
	/// <param name="rhs">[in,out] The right hand side.</param>
	/// <returns>A shallow copy of this object.</returns>
	Child3& operator=(Child3&& rhs) noexcept;

	/// <summary>
	/// Destructor. It closes the Child3 and releases the used resources.
	/// </summary>
	~Child3();
};