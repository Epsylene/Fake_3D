function runSimulator(simulator) {
	simulator
		.setEngineConfig((engineConf) => {
			engineConf.plotter.scale = {
				x : 50,
				y : 50,
			};
			engineConf.plotter.displayGrid = false;
		})
		.addObjects(pSObject, 1, 25, -25, 0, 20)
	;
}
