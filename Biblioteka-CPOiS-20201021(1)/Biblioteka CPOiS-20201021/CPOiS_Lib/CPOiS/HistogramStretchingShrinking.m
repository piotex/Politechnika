%% HistogramStretchingShrinking
% 
%  Places the lowest/highest input level on the specified parameter values
% 
function HistogramStretchingShrinking(block)

setup(block);
%endfunction

%% Function: setup
function setup(block)

% Register original number of ports based on settings in Mask Dialog
block.NumInputPorts = 1;
block.NumOutputPorts = 1;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;
    
% Override input port properties
block.InputPort(1).DatatypeID  = -1;  % 
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DimensionsMode = 'Variable';

% Override output port properties
block.OutputPort(1).DatatypeID  = 3; % uint8
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).DimensionsMode = 'Variable';
block.OutputPort(1).Dimensions = [1000,1000];

% Override parameters properties
block.NumDialogPrms     = 2;
block.DialogPrmsTunable = {'Tunable','Tunable'};

% Register sample times [0 offset]
block.SampleTimes = [1 0];

%% Options
% Specify if Accelerator should use TLC or call back into
% M-file
block.SetAccelRunOnTLC(false);

% Register methods called during update diagram/compilation

block.RegBlockMethod('CheckParameters',      @CheckPrms);
block.RegBlockMethod('ProcessParameters',    @ProcessPrms);
block.RegBlockMethod('PostPropagationSetup', @DoPostPropSetup);
block.RegBlockMethod('Outputs',              @Outputs);
block.RegBlockMethod('Terminate',            @Terminate);
%endfunction

%% Function: CheckPrms
function CheckPrms(block)

minimum = block.DialogPrm(1).Data;
maximum = block.DialogPrm(2).Data;

if ~(0==(minimum-fix(minimum)))
    error('Enter an integer value');
end

if ~(0==(maximum-fix(maximum)))
    error('Enter an integer value');
end

if minimum<0
    error('Enter non-negative value');
end

if maximum<0
    error('Enter positive value');
end

if minimum>255
    error('Enter smaller value');
end

if maximum>255
    error('Enter smaller value');
end

if minimum>=maximum
    error('Minimum value should be smaller than maximum value');
end
%endfunction

%% Function: ProcessPrms
function ProcessPrms(block)
% Update run time parameters
block.AutoUpdateRuntimePrms;
%endfunction

%% Function: DoPostPropSetup
function DoPostPropSetup(block)

% Register all tunable parameters as runtime parameters.
block.AutoRegRuntimePrms;
%endfunction

%% Function: Outputs
function Outputs(block)

minimum = block.DialogPrm(1).Data;
maximum = block.DialogPrm(2).Data;

sigVal     = block.InputPort(1).Data;

block.OutputPort(1).CurrentDimensions = size(sigVal);
im = sigVal;
im(find(ismember(im,-Inf))) = min(im(~ismember(im,-Inf)));
im(find(ismember(im,Inf))) = max(im(~ismember(im,Inf)));
im = im - min(min(im));
if isinteger(im)
    im = double(im2double(im)/max(max(im2double(im))))
else
    im = double(im/max(max(im)));
end

block.OutputPort(1).Data = im2uint8(imadjust(im,[0,1],[minimum/255,maximum/255]));
%endfunction

%% Function: Terminate
function Terminate(block)
%endfunction