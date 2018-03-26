modelName = {'e_coli_core'; 'iAB_RBC_283'; 'iAF692'; 'iAF987'; 'iAT_PLT_636'; 'iHN637'; 'iIT341'; 'iJB785'; 'iJN678'; 'iJN746'; 'iJR904'; 'iLJ478'; 'iMM904'; 'iND750'; 'iNF517'; 'iNJ661'; 'iSB619'; 'iYO844'};
mongoose_rxn = [20 85 200 394 104 259 118 102 188 402 408 265 711 627 224 281 278 475]';
cobra_rnx = [8 16 206 0 1 261 118 108 188 402 408 267 692 603 241 284 293 593]';
mongoose_time = [0.0426 0.2293 0.2799 0.62624 0.67245 0.3962 0.1650 0.3347 0.2805 0.4052 0.3831 0.2720 0.8774 0.5615 0.2423 0.5175 0.2473 0.6027]';
cobra_time = [0.388 1.9588 4.0372 -1 32.5235 4.4419 4.0329 6.7253 6.1357 10.957 12.25 3.2196 43.9767 22.0524 4.3166 10.5136 4.0554 16.402]';

%%% Small models: number of blocked reactions
% plot
figure
bar(1:18, [mongoose_rxn cobra_rnx], 1);
% bar labels
xticks(1:18);
xticklabels(modelName);
ax = gca;
ax.XTickLabelRotation = -45;
%chart labels
ylabel('No. of blocked reactions');
%legend and title
legend('Mongoose', 'Cobra');

%%% Small models: time cost
% plot
figure
bar(1:18, [mongoose_time cobra_time], 1);
% bar labels
xticks(1:18);
xticklabels(modelName);
ax = gca;
ax.XTickLabelRotation = -45;
%chart labels
ylabel('Analysis Time(s)');
%legend and title
legend('Mongoose', 'Cobra')

label = {'iMM904', 'iND750'};
%%% Yeast model: number of blocked reactions
mongoose_rxnvalue = [711 627]';
cobra_rxnvalue = [692 603]';
% plot
figure
bar(1:2, [mongoose_rxnvalue cobra_rxnvalue], 1);
% bar labels
xticks(1:2);
xticklabels(label);
% labels
ylabel('# Blocked reactions, larger the better');
% lengend and title
legend('Mongoose', 'Cobra');
title('Yeast Model - # Blocked Reactions');

%%% Yeast model: time cost
mongoose_timevalue = [0.8774 0.5615]';
cobra_timevalue = [43.9767 22.0524]';
% plot
figure
bar(1:2, [mongoose_timevalue cobra_timevalue], 1);
% bar labels
xticks(1:2);
xticklabels(label);
% labels
ylabel('Analysis Time(s), smaller the better');
% lengend and title
legend('Mongoose', 'Cobra');
title('Yeast Model - Analysis Time');