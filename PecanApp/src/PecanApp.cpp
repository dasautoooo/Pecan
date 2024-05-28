#include "Pecan/Application.h"
#include "Pecan/EntryPoint.h"

#include "Pecan/Image.h"

class ExampleLayer : public Pecan::Layer
{
public:
    virtual void OnUIRender() override
    {
        ImGui::Begin("Hello");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

Pecan::Application* Pecan::CreateApplication(int argc, char** argv)
{
    Pecan::ApplicationSpecification spec;
    spec.Name = "Pecan Example";

    Pecan::Application* app = new Pecan::Application(spec);
    app->PushLayer<ExampleLayer>();
    app->SetMenubarCallback([app]()
                            {
                                if (ImGui::BeginMenu("File"))
                                {
                                    if (ImGui::MenuItem("Exit"))
                                    {
                                        app->Close();
                                    }
                                    ImGui::EndMenu();
                                }
                            });
    return app;
}