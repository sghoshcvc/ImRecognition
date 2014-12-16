function [phocs,words] = createLexAtts( )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
load(fullfile('model','SVT_lexicon_PHOCs_l2345_lb2_nb50.mat'));
phocs = lexicon.phocs;
embedding = readCCA(fullfile('model','CCA.bin'));
    phocs = bsxfun(@rdivide, phocs,sqrt(sum(phocs.*phocs)));
    phocs=  bsxfun(@minus, phocs,embedding.mphocs);
    phocs = embedding.Wy(:,1:embedding.K)' * phocs;
    phocs = (bsxfun(@rdivide, phocs, sqrt(sum(phocs.*phocs))));
    words = lexicon.words;
end

