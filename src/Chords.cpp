#include "plugin.hpp"


struct Chords : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		VOCT_OUTPUT,
		GATES_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		KEY_B_LIGHT,
		KEY_ASHARP_LIGHT,
		KEY_A_LIGHT,
		KEY_GSHARP_LIGHT,
		KEY_G_LIGHT,
		KEY_FSHARP_LIGHT,
		KEY_F_LIGHT,
		KEY_E_LIGHT,
		KEY_DSHARP_LIGHT,
		KEY_D_LIGHT,
		KEY_CSHARP_LIGHT,
		KEY_C_LIGHT,
		NUM_LIGHTS
	};

	Chords() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
	}

	void process(const ProcessArgs& args) override {
	}
};


struct ChordsWidget : ModuleWidget {
	ChordsWidget(Chords* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Chords.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(39.829, 104.782)), module, Chords::VOCT_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(39.782, 116.452)), module, Chords::GATES_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.493, 13.423)), module, Chords::KEY_B_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(13.232, 17.297)), module, Chords::KEY_ASHARP_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.51, 21.358)), module, Chords::KEY_A_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(13.249, 25.232)), module, Chords::KEY_GSHARP_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.496, 29.302)), module, Chords::KEY_G_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(13.236, 33.176)), module, Chords::KEY_FSHARP_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.463, 37.22)), module, Chords::KEY_F_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.515, 45.167)), module, Chords::KEY_E_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(13.231, 49.14)), module, Chords::KEY_DSHARP_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.515, 53.085)), module, Chords::KEY_D_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(13.184, 57.068)), module, Chords::KEY_CSHARP_LIGHT));
		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(22.468, 61.013)), module, Chords::KEY_C_LIGHT));
	}
};


Model* modelChords = createModel<Chords, ChordsWidget>("Chords");