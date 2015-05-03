#pragma once


#include "core/lux.h"
#include "engine/iplugin.h"
#include "universe\universe.h"


namespace Lux
{
	class LUX_NAVIGATION_API Navigation : public IPlugin
	{
		public:
			Navigation();
			virtual ~Navigation();

			virtual bool create(Engine& engine) LUX_OVERRIDE { return true; }
			virtual void destroy() LUX_OVERRIDE; 
			virtual Component createComponent(uint32_t, const Entity&) LUX_OVERRIDE { return Component::INVALID; }
			virtual const char* getName() const LUX_OVERRIDE { return "navigation"; }
			virtual void update(float dt) LUX_OVERRIDE;

			void navigate(Entity e, const Vec3& dest, float speed);
			bool load(const char path[]);
			void draw();

		private:
			struct NavigationImpl* m_impl;
	};


	extern "C"
	{
		LUX_NAVIGATION_API IPlugin* createPlugin();
	}


}