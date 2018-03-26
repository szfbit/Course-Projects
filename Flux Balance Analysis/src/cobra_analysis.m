% initialize the toolbox
initCobraToolbox;
% go to the folder storing models
cd /Users/WYJ/cobratoolbox/models;
% read the files in the folder
files = dir('/Users/WYJ/cobratoolbox/models/*.mat');
% number of files in the folder
n = length(files);
% initialize arrays
name = strings(n);
result = zeros(n);
elapse = zeros(n);
nGenes = zeros(n);
nRxns = zeros(n);
nMets = zeros(n);
nRank = zeros(n);
nDof = zeros(n);

for i=1:n
    model = readCbModel(files(i).name);
    name(i) = model.modelID;
    nGenes(i) = length(model.genes);
    nRxns(i) = length(model.rxns);
    nMets(i) = length(model.mets);
    nRank(i) = rank(full(model.S));
    nDof(i) = nRxns(i) - nRank(i);
    
    solution1=optimizeCbModel(model);
    printFluxVector(model,solution1.x,true,true);
    
    model2=changeRxnBounds(model,'EX_glc__D_e',-1,'l');
    solution2=optimizeCbModel(model2);
    printFluxVector(model2,solution2.x,true,true);
    
    model2_high=changeRxnBounds(model,'EX_glc__D_e',-6,'l');
    solution2_high=optimizeCbModel(model2_high);
    printFluxVector(model2_high,solution2_high.x,true,true);
    
    model3=changeObjective(model,{'BIOMASS_Ecoli','EX_etoh_e'},[0,1]);
    solution3=optimizeCbModel(model3);
    printFluxVector(model3,solution3.x,true,true);
    
    model4=changeRxnBounds(model,'EX_o2_e',0,'l');
    solution4=optimizeCbModel(model4);
    printFluxVector(model4,solution4.x,true,true);
    
    % aerobic
    [minfluxaerobic,maxfluxaerobic]=fluxVariability(model,100);
    % anaerobic
    model5=changeRxnBounds(model,'EX_o2_e',0,'l');
    [minfluxanaerobic,maxfluxanaerobic]=fluxVariability(model5);
    [minfluxaerobic_50,maxfluxaerobic_50]=fluxVariability(model,100,0.5);
    
    % aerobic
    grRatioFBA=singleGeneDeletion(model,'FBA');
    fprintf(nnz(grRatioFBA));
    % anaerobic
    model6=changeRxnBounds(model,'EX_o2_e',0,'l');
    grRatioFBA_an=singleGeneDeletion(model6,'FBA');
    fprintf(nnz(~isnan(grRatioFBA_an)));
    
    try
        tic;% start timing
        result(i) = length(findBlockedReaction(model));%find the blocked reactions
    catch
        fprintf('Running time error! Cobra cannot compute the model given.');
    end
    toc;% end timinig
    elapse(i) = toc;% note down the result in [11 22 33...]
end