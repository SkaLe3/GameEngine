#include "pch.h"
#include "LayerStack.h"

namespace Engine {

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		EG_PROFILE_FUNCTION();
		m_Layers.emplace_back(layer); 
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		EG_PROFILE_FUNCTION();
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			layer->OnDetach();
			m_Layers.erase(it);
		}
	}
}
