#ifndef COMPONENT_H
#define COMPONENT_H

namespace min
{
	class Actor;

	// Components are basic piece of any actor.
	class Component
	{
	public:
		Component( Actor *owner )
		{
			if ( m_Owner == nullptr )
				m_Owner = owner;;
		}

		virtual ~Component() {}

		// Will be called before world starts ticking. (Only once)
		inline virtual void Birth() {}

		// Will be called after the "Birth" function. (Only once)
		inline virtual void Begin() {}

		// Will be called every frame.
		inline virtual void OnTick( float deltaTime ) {}

		// Will be called when owner actor gets enabled.
		inline virtual void OnEnable() {}

		// Will be called when owner actor gets disabled.
		inline virtual void OnDisable() {}

		// Will be called when the owner world gets disabled.
		inline virtual void OnShutdown() {}

		// Will be called when owner actor gets destroyed.
		inline virtual void OnDestroy() {}

		// Gets called when collision happens for the owner of this component.
		inline virtual void OnCollision( Actor *other ) {}

		inline Actor *GetOwner() { return m_Owner; }
		inline void SetOwner( Actor *actor ) { m_Owner = actor; }
		inline bool &GetIsEnabled() { return m_IsEnabled; }

	private:
		Actor *m_Owner = nullptr;
		bool m_IsEnabled = true;
	};
}

#endif // !COMPONENT_H