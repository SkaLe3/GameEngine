#include "SceneHierarchyPanel.h"

#include "Engine/Scene/Components.h"
#include <Engine/Core/Log.h>
#include <imgui/imgui.h>

namespace Engine {


	SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& context)
	{
		SetContext(context);
	}

	void SceneHierarchyPanel::SetContext(const Ref<Scene>& context)
	{
		m_Context = context;
	}

	void SceneHierarchyPanel::OnImGuiRender()
	{
		ImGui::Begin("Scene Hierarchy");

		m_Context->m_Registry.each([&](auto entityID)
		{
			Entity entity{ entityID, m_Context.get() };
			auto& tc = entity.GetComponent<TagComponent>();
			ImGui::Text("%s", tc.Tag.c_str());
		});

		ImGui::End();
	}

}