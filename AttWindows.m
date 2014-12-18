function  attsWin  = AttWindows(windows,atts,N,D )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
Blocksize =16;
embeddingInt = readCCA(fullfile('model','CCA.bin'));
windows =[windows(:,1)+1 windows(:,2)+1 windows(:,3)+1 windows(:,4)+1];
windows = double(windows);
 windows = [ceil(windows(:,1)/Blocksize) ceil(windows(:,2)/Blocksize) ceil(windows(:,3)/Blocksize) ceil(windows(:,4)/Blocksize)];
 ImageNorm = zeros(N,D,'single');
 
 attsWin =Cal_feat_window( windows,atts,ImageNorm);
 
 if ~isempty(attsWin)
                
                attsWin = (bsxfun(@rdivide, attsWin, sqrt(sum(attsWin.*attsWin))));
                attsWin(isnan(attsWin)) = 0;
                attsWin =  bsxfun(@minus, attsWin,embeddingInt.matts);
                
                % Embed  test
                attsWin = embeddingInt.Wx(:,1:embeddingInt.K)' * attsWin;
                
                % L2 normalize (critical)
                attsWin = (bsxfun(@rdivide, attsWin, sqrt(sum(attsWin.*attsWin))));
            else
                attsWin = zeros(embeddingInt.K,length(idxc),'single');
   end
end

