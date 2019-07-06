#include <katana.hpp>

#include <input_listener.hpp>

#include <scene/controllers/render_controller.hpp>

KatanaApi* ktApi = 0;


class actorGameCamera : public Actor, public InputListenerWrap {
    GameObject* node = 0;
public:
    void onInit() {
        node = getSession()->getScene()->getRoot()->createChild();
        getSession()->getScene()->getController<RenderController>()
            ->setDefaultCamera(node->get<Camera>().get());
        node->get<Camera>()->setZFar(1000.0f);
        node->get<Camera>()->setFov(0.76);

        auto t = node->getTransform();
        t->translate(-1.8, 3, 7);
        t->rotate(-0.2f, gfxm::vec3(1,0,0));
    }
};


static class sessMain : public ktSession {
    std::shared_ptr<OmniLight> light;

public:
    virtual void onStart() {
        // TODO: Initialize your session here
        getScene()->getRoot()->createChild()->read("assets/level3.so");

        createActor<actorGameCamera>();

        light = getScene()->getRoot()->createChild()->get<OmniLight>();
        light->intensity = 20.0f;
        light->radius = 3.0f;
        light->getOwner()->getTransform()->translate(gfxm::vec3(.0f, 1.0f, .0f));
    }

    virtual void onUpdate() {
        // TODO: Frame update
        light->getOwner()->getTransform()->setPosition(
            gfxm::vec3(sin(ktApi->getTime()),1,cos(ktApi->getTime()))
        );
        light->color = gfxm::vec3(
            sin(ktApi->getTime()) + 1.0f,
            cos(ktApi->getTime()) + 1.0f,
            sin(ktApi->getTime()) + 1.0f
        );
    }

    virtual void onCleanup() {
        // TODO: Cleanup
    }
} sess_main;


int ktStartup(KatanaApi* kt_api) {
    ktApi = kt_api;
    kt_api->run(&sess_main);
    return 0;
}