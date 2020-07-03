function runSimulator(simulator) {
	simulator
		.setEngineConfig((engineConf) => {
			engineConf.plotter.scale = {
				x : 81,
				y : 50,
			};
			engineConf.plotter.displayGrid = false;
		})
		.addObjects(pSObject, 1)
	;
}
