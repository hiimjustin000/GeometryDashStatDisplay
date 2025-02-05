#include <Geode/modify/PauseLayer.hpp>
#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>
/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;
class $modify(StatDisplaySettingsLayer, PauseLayer) {
	// add the settings button to the pause menu
	void customSetup() {
		PauseLayer::customSetup();
		auto menu = getChildByID("right-button-menu");
		if ((menu!=nullptr) && Mod::get()->template getSettingValue<bool>("showPause")) {
			auto settingBtn = CCMenuItemSpriteExtra::create(
				CircleButtonSprite::createWithSprite("SettingsIcon.png"_spr, 1.f, CircleBaseColor::Green, CircleBaseSize::Tiny),
				this, menu_selector(StatDisplaySettingsLayer::onSetting)
			);
			menu->addChild(settingBtn);
			menu->updateLayout();
		}
	}
	void onSetting(CCObject*) {
		geode::openSettingsPopup(Mod::get());
	}
};